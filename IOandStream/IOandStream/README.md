# IO and file stram

## C++은 스트림 추상화(Stream abstraction)를 제공함.

- 스트림을 이용해 IO장치와 작업할 수 있게 해줌.
- 스트림은 실제 장치와 독립적인 인터페이스임.  
  -> 우리는 스트림 인터페이스를 통해 코딩할 수 있고, 스트림과 연결된 장치에 대해 많은 신경 쓸 필요 없음.
- 스트림은 sequence of byte임.
- C++은 다양한 유형의 스트림을 제공함.  
  -> input or output or both.

## Common header files

### 스트림 IO와 작업할 수 있게 하는 가장 일반적인 3가지 헤더 파일.

- iostream: 형식화된 스트림으로의 입력, 스트림으로 부터의 출력에 필요한 definition을 제공함.
- fstream: 파일 스트림과 주고 받는 형식화된 IO에 대한 definition 제공.
- iomanip: manipulators에 대한 definition을 제공.  
  -> 특정 방식으로 iostream들을 형식화할 수 있음.
- 이러한 헤더파일 포함하여 파일 IO에 사용할 수 있는 많은 C++ 클래스들에 접근 가능함.

## Commonly used file stream classes

- ios: ios 클래스는 형식이 지정된 IO와 형식이 지정되지 않은 IO에 대한 기본적인 지원 제공. iostream 계층 구조에서 대부분의 다른 클래스에 대한 base class 역할을 함.
- ifstream: 파일에서 높은 수준의 입력 작업을 제공. 따라서 file에서 읽기 위해 객체를 ifstream 객체로 선언할 수 있음.
- ofstream: 파일에서 높은 수준의 출력 작업 제공.
- fstream: 파일 기반 stream에서 높은 수준의 IO를 제공. ifstream과 ofstream에서 다중 상속 이용해 파생됨. 파일 입출력 동시에 수행해야 하는 경우 사용됨.
- stringstream: 메모리 기반 string에 대한 높은 수준의 작업 제공.  
  cin, cout과 삽입, 추출 연산자로 입출력 할 수 있는 것처럼, cin, cout과 삽입, 추출 연산자와 메모리 기반 문자열를 함께 사용하여 입출력 할 수 있게해줌.

## Global stream objects

### main()이 실행되기 전 초기화 되며, iostream include 하여 사용.

- cin: standard input stream이며, 기본적으로 키보드와 연결됨. istream class의 인스턴스임.
- cout: standard output stream이며, 기본적으로 콘솔과 연결됨. ostream class의 인스턴스임.
- cin과 cout은 일반적으로 버퍼 스트림임(buffered stream).  
  -> cin은 사용자가 엔터 누를 때까지 입력되지 않음. cout은 스트림 버퍼가 가득 찼을 때 or std::endl 사용 or stream을 flush 해야만 출력 발생.
- cerr, clog는 각각 표준 오류 스트림, 표준 로그 스트림이며, 기본적으로 콘솔에 연결됨. 둘다 unbufferd stream임.  
  -> 우리가 필요할 때 입출력 가능.
- 이러한 스트림을 리디렉션하여 파일로 입출력 할 수도 있음.  


# Stream Manipulators

- C++ 스트림에는 formatter를 제어하기 위해 사용할 수 있는 유용한 멤버 메서드들이 많이 있음.  
  -> 입, 출력 스트림과 작동하는 메서드가 모두 존재하나 출력 형식을 지정하는 것이 훨씬 일반적임.
- 형식화를 위해 스트림 조작할 때, 가끔은 우리가 만든 설정이 프로그램의 남은 모든 곳에 대해 영향을 주고, 가끔은 스트림에 배치된 다음 객체에만 영향을 주고, 또 가끔은 그 영향이 즉각적임.  
  -> 즉, 스트림을 조작했을 때, 그 영향의 지속 시간이 다양함.

## 대부분의 스트림 formatter는 두가지 버전으로 제공됨.

- 메서드 버전과 manipulator 버전.  
  -> 메서드 버전은 단순히 스트림 객체와 함께 사용하는 메서드 호출임.  
  ex) std::cout.width(10);  
  -> manipulator 버전은 스트림 삽입처럼 인라인으로 사용됨. -> 삽입 연산자를 오버로드하여 사용하기 쉽게 만들어져 있음.  
  ex) std::cout << std::setw(10);  
  manipulator 사용하려변 iomanip을 include 해야 함.
