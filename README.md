Test Hangul editor  for  broken characters when Linux,MSwindows , utf-8, euc-kr  
Or 
Text Editor programing  sample source cod  on c++ bulid ( gcc 64bit, QT creator,cmake)

 한글 인코딩시 깨짐문자들을 정상적으로 불러오기위한 테스트를 포함하는 간단한  텍스트 편집기를 보여주는 c++ 샘플소스 프로그래밍입니다.

README.md  by notepadQ 0.1 nightly (build unbuntu20LTS,QT creator and cmake) 20210926

README.md는 우분투20LTS에서 QT로 빌드된 노트패드큐 나이틀리 버전으로 작성되었습니다.

<table>
 <tr><td>version</td>
<td>function</td> <td>where is it ?</td> </tr>
   <tr><td>0.1</td>
<td>only QT c++  text editor frame </td> 
  <td>/GC</td>  </tr>
 <tr><td>0.2</td>
<td>Hangul decoder engine</td> 
    <td>/GC</td></tr>
 <tr><td>0.3</td>
<td>words finder window</td> 
   <td> main (now)</td> </tr>
 </table>

[build]
<table>
 <tr><td>build</td><td>spec</td><td>or</td>
   </tr>
 <tr><td>cmake</td><td>$ cmake  ./ <br>
$ make</td><td></td>
  <tr><td> qmake or QT </td><td>$ qmake notepadQ.pro -spec linux-g++ CONFIG+=debug
 <br>
$ make -j2</td><td>QT crearter</td>
   </tr>
   </tr>
 </table>



<hr>
 javascript version  test page :   https://uv337.github.io/
<table>   
   <tr>
     <td>   	ÇÏÃµ
       </td>
         <td> 하천
         </td>            
    </tr>
 </table>
 
 
 <hr>
 [Histroy]
 2021.10.6-  QT Creator  build is ok., cmake is no., qmake is yes, but not yet ,this has a fatal error 1. <br>
 2021.10.7 - issue#2 fixed <br>
 > qmake notepadQ.pro -spec linux-g++ CONFIG+=debug<br>
 > make -j2<br>
 2021.10.7[No. 2] - issue#2 option <br>
 > makdir ./release [build directiory] <br>
 > cd ./release [build directiory] <br>
 > qmake ../notepadQ.pro -spec linux-g++ CONFIG+=debug <br>
 > make -j2<br>
 
 
