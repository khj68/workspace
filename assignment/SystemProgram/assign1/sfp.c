#include "sfp.h"
#include <stdlib.h>

typedef unsigned short sfp;
#define bias 15 //bias ũ��� 2^5-1 -1 (exp bit�� 5��)

float fabs(float a) {
	if (a < 0) {
		return -a;
	}
	else {
		return a;
	}
}

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	else {
		return a;
	}
}

sfp int2sfp(int input){
	sfp newSfp = 0;
	long long binary = 0, temp_binary,ten =1;
	int E = 0, exp, i, index = 32768, count = -1, bin_count=0, sign=0;
	int frac = 0, frac_i = 1;

	if (input == 0) return 0;//0ó��
	if (input > 65504) return 31744; //+���Ѵ� ó��
	if (input < -65504) return 64512; //-���Ѵ� ó��

	if (input > 0) index /= 32;
	else { //���� ó��
		newSfp += index;
		index /= 32; 
		input *= -1; 
		sign = 1;
	}

	while (1) { //binary
		binary += input % 2 * ten; //binary��� int�� 10������ 2������ ǥ�� ex) 1101
		ten *= 10;
		bin_count++; // binary�� ���ڸ� ������ üũ
		input /= 2;
		if (input == 0) {
			break;
		}
	}

	if (bin_count > 11) { //round-to-zero ����
		while (bin_count != 11) {
			bin_count--;
			binary /= 10;
		}
		if (sign = 1) {
			binary += 1;
		}
	}

	temp_binary = binary;

	while ((temp_binary /= 10) != 0) { //E ���
		E++;
	}

	exp = E + bias; //exp ���
	newSfp += (exp * index); // exp�κ� ����
	temp_binary = binary;
	ten = 1;

	while (temp_binary >=10 ) { //�ڸ��� ������� temp ���, ten�� ���� �ڸ��� �ľ�
		temp_binary /= 10;
		ten *= 10;
		count++;
	}

	for (i = 0; i < count+1; i++) { //ã�� �ڸ�����ŭ index ����
		index /= 2;
	}

	binary -= ten; // 1.xxx �����̱⿡ 1 ����

	while (binary != 0) { //frac �κ� ����
		frac += binary % 10 * frac_i;
		frac_i *= 2;
		binary /= 10;
	}

	newSfp += frac * index;
	
	return newSfp;
}

int sfp2int(sfp input){
	int binary = 0, index = 15, ten = 1,two=1, newInt = 0, binary_count=0;
	int E, exp=0;

	if (input == 0) return 0;//0ó��
	if (input == 31744) return 2147483647; //+���Ѵ� ó��
	if (input == 64512 || (input/1024)%32 == 31) return -2147483647; //-���Ѵ� ó��
	
	while (input % 2 == 0) {//1�� ��ġ ã�°�
		input /= 2;
		index--;
	}

	while (index != 5) { // frac ó���ϴ°�
		binary += input % 2 * ten;
		binary_count++;
		input /= 2;
		ten *= 10;
		index--;
	}
	binary += ten;

	while (index != 0) { // exp ó���ϴ°�
		exp += input % 2 * two;

		input /= 2;
		two *= 2;
		index--;
	}
	E = exp - bias; // E ����
	
	if (E < binary_count - 1) { // round-to-zero ����
		while (!(E == binary_count - 1)) {
			binary /= 10;
			binary_count--;
		}
	}
	two = 1;

	while (binary != 0) { //binary�� ���� int�� ����
		newInt += binary % 10 * two;

		binary /= 10;
		two *= 2;
	}
	
	if (input == 1) newInt = -newInt; //������ ��� -��ȣ ó��

	return newInt;
}

sfp float2sfp(float input){
	sfp newSfp=0;
	int index = 32768, i=0, find_one = 0, integer = 0, integer_bin = 0, integer_count = 0;
	int bin_i = 0, two = 1, ten = 1, frac_i, frac = 0, E = 1, integer_save, exp, sign =0;
	int binary[16];

	if (fabs(input)< 0.000001) return 0;//0ó��
	if (input > 65504) return 31744; //+���Ѵ� ó��
	if (input < -65504) return 64512; //-���Ѵ� ó��

	memset(binary, 0, 16*sizeof(int)); //0���� �ʱ�ȭ

	if (input < 0) { //���� ó��
		input *= -1;
		newSfp += index;
		sign = 1;
	}
	index /= 32;

	if (input >= 1) { // integer�κ��� ũ�Ⱑ ������ �ľ�
		while (input >= 1) {
			input -= 1;
			integer++;
		}
	} 
	integer_save = integer;

	if (integer != 0) { //integer�κ� binary�� ��ȯ
		while (integer != 0) {
			integer_bin += (integer % 2) * ten;
			ten *= 10;
			integer /= 2;
			integer_count++;
		}
	}
	for (i = integer_count - 1; i >= 0; i--) {//��ȯ�� binary�� �� binary�� ����
		binary[i] = integer_bin % 10;
		integer_bin /= 10;
	}
	bin_i += integer_count;
	
	while (1) { //�Ҽ� �κ��� binary ���� ����
		input *= 2;

		if (input > 1) {
			input -= 1;
			binary[bin_i] = 1;
		}
		else {
			binary[bin_i] = 0;
		}
		
		if (fabs(input - 1) < 0.001) { // ���������� ��ȯ�� �� �迭�� ������
			binary[bin_i] = 1;
			bin_i++;
			break;
		}
		bin_i++;
	}

	if (bin_i > 10) { //round-to-zero ����
		while (bin_i != 10) {
			binary[bin_i] = 0;
			bin_i--;
		}

		if (sign == 1) {
			if (binary[bin_i] == 0) {
				binary[bin_i] = 1;
			}
			else {
				binary[bin_i] = 0;
				int i = 9;
				while (binary[i] != 0) {
					binary[i] = 0;
					i--;
				}
				binary[i] = 1;
			}
		}
	}
	
	while (binary[find_one] != 1) { //if �����κ� �����ϸ� �״�� ���, ���� 0�̸� 1���ö����� ã��
		find_one++;
		E++;
	}
	find_one++;

	if (E > 1 || integer_save == 0) { //E�� ����
		E *= -1;
		frac_i = bin_i + E;
	}

	if (integer_count > 0) { //E�� ����
		E = integer_count - 1;
		frac_i = bin_i - find_one;
	}
	
	exp = E + bias; //exp�� ����
	newSfp += index * exp; //Sfp�� exp�κ� ����
	two = 1;

	for (i = 1; i < frac_i; i++) { //�ڸ��� ����
		two *= 2;
	}	
	index /= two*2;
	
	while (two != 0) { // frac�κ� ����
		if (binary[find_one++] == 1) {
			frac += two;
		}
		two /= 2;
	}
	newSfp += index * frac; //Sfp�� frac�κ� ����

	return newSfp;
}

float sfp2float(sfp input){
	int binary[16];
	int	index = 15, two = 1, i=0,ten =1,sign= 0;
	int E, exp = 0, frac_i = 0,point;
	float frac_two = 1.0, newFloat = 0.0;
	
	memset(binary, 0, 16 * sizeof(int)); //binary �ʱ�ȭ

	if (input > 32768) { //ũ�⸦ ���� �������� �ľ�
		sign = 1;
	}

	while (index != 5) { // frac ó���ϴ°�
		binary[index] += input % 2;
		input /= 2;
		index--;
		frac_i++;
	}

	binary[index] = 1;
	int find_one = index;

	while (index > 0 ) { // exp ó���ϴ°�
		exp += input % 2 * two;

		input /= 2;
		two *= 2;
		index--;
	}
	E = exp - bias; //E�� ����
	point = find_one + E; // �Ҽ��� ��ġ �ľ�
	two = 1;

	for (i = point; i >= 0; i--) {//�����κ� ����
		newFloat += two * binary[i];
		two *= 2;
	}
	frac_two = 0.5;

	for (i = point + 1; i < 16; i++) {//�Ҽ��κ� ����
		newFloat += frac_two * binary[i];
		frac_two *= 0.5;
	}

	if (sign == 1) newFloat = -newFloat; //-��ȣ ó��

	return newFloat;
}

sfp sfp_add(sfp a, sfp b){
	int a_exp = (a / 1024) % 32;
	int b_exp = (b / 1024) % 32;
	int exp_change = 0, round= 0, b_save;
	int two = 1,i, frac, a_sign = 0, b_sign = 0, sign = 0;
	sfp result = 0;
	int exp_differ;
	
	if (a_exp == 31 && a < 32768) { //a�� +���Ѵ��϶�
		if (b_exp == 31 && b > 32768) { //b�� +���Ѵ밡 �ƴ϶��
			return 31744 + 1; //NaN ��ȯ
		}
		return 31744; //+���Ѵ� ��ȯ
	}
	else if (a_exp == 31 && a > 32768) { //a�� -���Ѵ��϶�
		if (b_exp == 31 && b < 32768) { //b�� -���Ѵ밡 �ƴ϶��
			return 31744 + 1; // NaN ��ȯ
		}
		return 64512; //-���Ѵ� ��ȯ
	}
	else if ((a_exp == 31 && a / 1024 > 0) || (b_exp == 31 && b / 1024 > 0)) {//�� �� �ϳ��� NaN�̶��
		return 31744 + 1; //NaN ��ȯ
	}
	
	if (a_exp < b_exp) {
		sfp temp = a;
		a = b;
		b = temp;
		temp = a_exp;
		a_exp = b_exp;
		b_exp = temp;
	}
	if (a > 32768) a_sign = 1; //ũ�� ���� ��ȣ �ľ�
	if (b > 32768) b_sign = 1; //ũ�� ���� ��ȣ �ľ�

	if ( a_exp>=b_exp ) { // a�� E�� �� ũ�ų� ���� ���
		exp_differ = (a_exp > b_exp) ? a_exp - b_exp : 0; //exp ���̸� ���Ѱ�
		result += 1024 * a_exp;
		a %= 1024;
		b %= 1024;

		for (i = 0; i < exp_differ; i++) { // �ڸ��� ����
			two *= 2;
		}
		b_save = b+1024;

		if (two != 1) { //b�� ������ a�� ���߱�
			b += 1024;
			b /= two;
		}
		
		if (b_save != b * two) { //round-to-even�� �ؾ��ϴ��� ���� Ȯ��
			round = 1;
		}

		if (a_sign == 1 && b_sign ==1 ) {//������ ��ȣ�� ��쿡 ���� ����
			frac = a+ b;
			if (frac >= 1024 || two == 1) {
				frac /= 2;
				exp_change += 1024;
			}
			sign = 1;
		}
		else if (a_sign ==1 && b_sign == 0) {
			frac = abs(a+1024 - b);
			if (a_exp > b_exp) {
				sign = 1;
			}
		}
		else if (a_sign == 0 && b_sign == 1) {
			frac = abs(a+1024 - b);
			if (b_exp > a_exp) {
				sign = 1;
			}
		}
		else {
			frac = a + b;
			if (frac >= 1024 || two == 1) { //right-shift����
				frac /= 2;
				exp_change += 1024;
			}
		}

		if ((a_sign == 1 && b_sign==0)|| (b_sign == 1 && a_sign ==0)) {
			if (frac < 1024) { //left-shift ����
				while (frac < 1024) {
					frac *= 2;
					exp_change -= 1024;
				}
			}
			frac -= 1024;
		}
		frac += exp_change;

		if (sign == 1) frac += 32768; //��ȣ ó��
		result += frac;

		if (round == 1 && result%2 == 1) { // round-to-even ó��
				result += 1;
		}
	}
	
	return result;
}


char* sfp2bits(sfp result){
	int i, index = 1;
	char *bit = (char*)malloc(sizeof(char) * 17);
	memset(bit, '0', 17*sizeof(char));
	bit[16] = '\0';

	for (i = 15; i >= 0; i--) { //0,1�� ���� ���ڿ��� ����
		if (result % 2 == 0) {
			bit[i] = '0';
		}
		else {
			bit[i] = '1';
		}

		result /= 2;
	}
	
	return bit;
}


