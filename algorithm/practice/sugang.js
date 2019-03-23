let tried = 0;
let macroList = new Array(5);
// let currentTO = [120,40,40,46,40];

// document.querySelector('#\32 > td:nth-child(2) > span')
// //*[@id="2"]/td[2]/span
// #\32 > td:nth-child(2) > span

// <span class="btn2 blue" onclick="choice('2','N')">신청</span>

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}




var jq = document.createElement('script');
jq.src = "//ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js";
document.getElementsByTagName('head')[0].appendChild(jq);
// ... give time for script to load, then type.
jQuery.noConflict();

//*[@id="4"]/td[2]/span
//*[@id="2"]/td[2]/span
//*[@id="5"]/td[2]/span

async function runMacro(){
    tried++;
    console.log('시도 횟수: '+tried);
    top.Main.contentFrame.topFrame.goMenu('1');
    await sleep(5000);
    
    
    let data=top.Main.contentFrame.mainFrame.$('#listLecture').jqGrid('getRowData',macroList[0]);
    // let lectureName;
    // let lectureNo;
    // let TO;
    // console.log('macro begin');
    
    console.log(data[1].tot);
    if(data[1].tot != '36 / 36'){
        $x('.//*[@id="2"]/td[2]/span')[0].click()
        return;
    }
    
    console.log(data[3].tot);

    if(data[3].tot != '36 / 36'){
        $x('.//*[@id="4"]/td[2]/span')[0].click()
        return;
    }
    
    console.log(data[4].tot);

    if(data[4].tot != '36 / 36'){
        $x('.//*[@id="5"]/td[2]/span')[0].click()
        return;
    }

    runMacro();
}
    
    // if(data){
    //     lectureName = data.gyogwamok_nm;
    //     lectureNo = data.haksu_no;
    //     TO = data.tot_dhw;
    //     console.log(lectureName);
    //     console.log(lectureNo);
    //     console.log(TO);
    // }else{
    //     console.log('로딩오류 발생으로 5초 후 다시 시작');
    //     await sleep(5000);
    //     break;
    // }
    
    // if(TO == currentTO[i]){
    //     console.log('['+lectureNo + ']' + lectureName + '정원초과:'+TO);
    // }else if(data&&TO&& TO!= currentTO[i]){
    //     beep(100,260,200,3);
    //     login(top.Main.contentFrame.mainFrame.$('#listLecture').jqGrid('getRowData',macroList[i]).params + "@0@N");
    //     await sleep(8000);
    //     console.log('['+lectureNo+']' + lectureName+'수강신청 성공:' + TO);
    //     return;
    // }else{
    //     console.log('로딩오류 발생으로 5초 후 다시 시작');
    //     break;
    // }
    //     }
    //     runMacro();
    // }catch(e){
    //     runMacro();
    // }
}