# TIL   / 2018 - 10 - 27
![](2018-11-22-13-44-58.png)
```
GIT
소스 코드 관리를 위한 분산 버전 관리 시스템
```

>### Git 호스팅 웹서비스

![](2018-11-22-13-50-06.png)
[출처](https://medium.com/flow-ci/github-vs-bitbucket-vs-gitlab-vs-coding-7cf2b43888a1)

1. GitHub

private 은 유료. LFS트래픽 제한
Large File Storage

2. Bitbucket

리포지터리당 1GB , private 무료(5인까지)

3. GitLab

private 무료 (협업자수 제한 없음)
리포지터리당 10GB 빌드머신 구현에 용의
설치형, 호스팅형 두가지.
가끔씩 불안정함(``6시간 데이터 유실 사건!``)

##### 나의 git 랭킹은?  http://git-awards.com/

> ### Source Tree

![https://www.sourcetreeapp.com/](2018-11-22-14-03-04.png)
+ 로컬에서 git 을 편리하게 사용할 수 있도록 만들어진 유틸리티

+ BitBucket 계정 필요

> #### 따라해보자!

1. 새로운 유니티 프로젝트 CalcGame 생성
2. git 기본 설정 (IgnoreFile, Unity git 사용 설정, 구글 에서 unity Project Settings git 검색)
4. github 에서 새로운 리포지터리 CalcGame 생성
5. 소스트리를 이용하여 Calc Game 로컬 리포지터리 생성
6. 소스 트리를 로컬리포지터리와 git 리포지터리 연결
7. 
8.  


> #### 유니티 프로젝트 설정하기!

1. Edit -> ProjectSettings -> Editor 를 선택
![](2018-11-22-14-20-50.png)

    1.1 Version control 
    VCS 을 설정하거나 Unity 에서 .meta 파일을 사용해 데이터를 저장하는 크게 두가지로 나뉜다. __Unity Personal 에서는 VCS 를 설정하는 것은 사용할 수 없다.__ 
    .meta 파일을 숨김파일로 지정하느냐 일반 파일로 지정하느냐의 차이인데 Git 에서는 숨김 파일은 취급하지 않기 때문에 Visible Meta Files 옵션을 사용한다.
    1.2 Asset Serialization 
    Unity 프로젝트에서 Unity 에서 직접 지정하는 확장자가 붙은 파일들을 어떻게 취급하냐를 설정하는 옵션이다. Unity 프로젝트에서는 두가지 방식으로 파일을 취급할 수 있는데 하나는 텍스트 형식으로 취급하는 것과 하나는 바이너리 형식으로 취급하는 것이다. 옵션의 선택지를 보면 총 3가지 인데 맨처음 Mixed 는 Unity 에서 파일마다 지정한 방식대로 텍스트냐 바이너리냐를 따라가는 것이고 나머지 두개(Force Text, Force Binary)는 무조건 한가지 방식으로 모든 파일들을 통일하는 것이다. 여러 용도로 텍스트를 사용하므로 Force Text 옵션을 사용한다.

> #### .gitignore 설정.

유니티에서 라이브러리 디렉토리는 프로젝트의 캐시 데이터 이므로, 굳이 없어도 다시끔 만들어 지게 된다. 


> #### Project 클론을 위한 권한 할당해주기
> ![](2018-11-22-14-52-19.png)

아이디를 입력해주면 해당 아이디의 메일에 메일이 오면 수락후, 

![](2018-11-22-14-57-08.png)

클론!

![](2018-11-22-14-58-05.png)

이제 두명이서 한개의 유니티 프로젝트를 작업할수 있게되었다.

만약 작업자 A 가 작업을 하고 커밋을 하였을때, 패치 버튼을 누른다면, 리포지토리에서 받지않는 새로운 내역이 뜬다.

Pull을 눌러서 유니티 프로젝트를 업데이트 시켜주자.

![](2018-11-22-15-19-10.png)