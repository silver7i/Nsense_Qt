# QT 에서의 얼굴검출 작업 (보류)

얼굴검출 모델을 사용하여 (1)동영상을 한번 재생하면서 영상에 나오는 사람얼굴을 검출한 뒤  
(2)다시 재생했을 때에 검출된 얼굴을 오른쪽에 보여주는 작업을 진행함.

쓰레드를 사용하여 프레임을 받아서 Queue에 저장한 뒤, 다른 쓰레드로 저장된 프레임의 이미지처리를 진행함.
검출된 얼굴에 블러처리 하는 기능 작업(보류)


```검출과정은 회사의 테스트 코드와 모델을 사용하였다.```

```
* 1. Open / 파일 선택 창이 뜸. (video 선택)
* 2. Save Start / 영상이 재생되면서 얼굴검출한 뒤
* 3. stop / 검출된 얼굴이 저장됨
* 4. Face View / 검출되어 저장된 얼굴의 face id 와 검출된 얼굴을 따로 보여줌
```
<img width="1047" alt="Qt 얼굴검출 작업" src="https://github.com/silver7i/Nsense_Qt/assets/77370836/032343e3-48ec-4370-8e44-929fdc661396">

