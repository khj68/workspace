from selenium import webdriver
from time import sleep

driver = webdriver.Chrome(r'D:\Chromedriver\chromedriver.exe')
driver.get('https://sugang.skku.edu')

sleep(10)


# driver.find_element_by_name('id').send_keys('2014312516')
# driver.find_element_by_name('pwd').send_keys('tldptmxk2')

# driver.find_element_by_xpath('//*[@id="btn_login"]').click()
# # driver.find_element_by_xpath('//*[@id="btn_login"]').click()

# while(True) :
# elem = driver.find_element_by_xpath('//*[@id="1"]/td[2]/span').click()
driver.findElement(By.xpath('span[@class='']))
sleep(5)
