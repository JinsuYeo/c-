#  STL
-STL은 재사용 가능하고 adaptable하며 generic한 클래스와 함수들임.   
STL은 템플릿 함수와 클래스를 사용하여 구현됨. 거대한 템플릿 클래스 라이브러리(Standard Template Library).   
STL은 일반적으로 사용되는 컨테이너 모음임. 세가지 주요 구성요소가 있음. -> Container, Algorithm, Iterator.    <- 각자 독립적으로 설계되었으나 원활하게 함께 작동함.   
컨테이너 - 벡터, 덱, 스택, 큐 등.   
알고리즘 - find, max, sort, accumulate 등.  
이터레이터 - forward, reverse, by value, by reference, const 등.   
예를 들어 vector를 정렬할 때, vector는 컨테이너, sort()는 알고리즘, sort에 인자로 들어가는 v.begin(), v.end() 가 iterator라고 볼 수 있음.   

-컨테이너의 종류에는 Sequence container(순서를 유지하는 컨테이너, vector, list 등), Associative container(사전에 정의된 순서로 요소 삽입 or 순서 전혀 없음, map, set등), Container adapters(다른 컨테이너의 변형 iterator 지원 x, STL 알고리즘과 사용 불가능. but 프로그래밍에 일반적으로 사용되어 STL이 이것들에 대한 지원 제공함, stack, queue 등)가 있음.

-이터레이터의 종류에는 Input iterator(컨테이너 요소를 프로그램에서 사용할 수 있게 함), Output iterator(시퀀스를 iterate(순회, 반복)하고, 컨테이너에 요소를 씀), Forward iterator(시퀀스를 순방향으로 iterate, 모든 요소 일거나 쓸 수 있음), Bi-dirctional iterator(순방향 반복자와 같지만 양방향으로 시퀀스 순회 가능), Random access iterators(아래 첨자(.)로 임의 접근 가능, ex)v.at(i)) 가 있음.

-STL algorithm은 약 60개 있고 주로 두가지 그룹으로 분류됨. -> Non-modifying(비수정 알고리즘), Modyfing(수정 알고리즘)으로 분류됨 <- 알고리즘이 시퀀스 수정하는지 여부에 따라 나뉨.


## STL Container
- STL container는 자료 구조임.
 거의 모든 타입의 객체 저장 가능.
 템플릿 기반 클래스로 구현됨.
 
- 각 컨테이너는 멤버 함수 집합을 가짐.   
 일부는 특정 컨테이너에 고유함.   
 모든 컨테이너가 사용할 수 있는 멤버 함수도 꽤 존재함.
 
- 각 컨테이너는 연결된 헤더 파일이 있음.    
 컨테이너 사용 시 nclude 해주어야 함.
 
 - 컨테이너에는 모든 기본 유형(primitive type) 저장 가능.   
  + 컨테이너에는 객체의 복사본이 저장되기 때문에 사용자 정의 타입 같은 유형은 복사 할당자, 복사 생성자(or default 복사 생성자) 혹은 효율성을 위한 이동 연산자나 생성자 등이 정의되어 있어야 함.   
  + 객체끼리 비교 가능해야 함. -> 비교 연산자들이 오버로드 되어있어야 함.   
  
  
  ## STL Iterator
  - 컨테이너를 일련의 요소들의 시퀀스로 생각, 처리 할 수 있게 해줌. 어떤 컨테이너든지(vector, map, set...).
  
  - 템플릿 클래스로 구현되며 iterator 객체 만들고 그것을 사용하여 컨테이너를 순회, iterate 함.
  
  - iterator와 사용되는 구문(Syntex)은 포인터 구문 처럼 생각될 수 있음.   
   역참조 연산자, 증가 및 감소 연산자 등 사용 가능.   
   -> 의도적으로 설계됨. C++ 프로그래머는 포인터 구문에 익숙하기 때문에 iterator 사용 방법 배우는 것이 쉬움.   
   
   - 대부분의 STL container는 iterator 사용해 순회할 수 있음(stack, queue 같은 몇 가지 예외 존재).   
   
   - iterator는 순회할 컨테이너의 타입에 따라 선언 되어야 함.   
   container_type::iterator_type iterator_name; 처럼 선언.   
   ex) std::vector<int>::iterator itl;  <- int vector에만 사용 가능.   
   auto itl; 처럼 사용하면 이해하기 더 쉬울 수 있음.
   
   - 거의 모든 STL container에 begin(), end() 메서드 존재. -> iterator 객체 반환함.   
    begin()은 컨테이너의 첫번째 요소, end()는 마지막 요소가 아니라 마지막 요소의 다음 번 위치를 반환함. centinel로 사용됨.   
    ex) auto it = vec.begin();
    
    - 범위 기반 for loop도 뒤에서 iterator 기반 루프로 변환되어서 사용됨.   
    ex) for(auto it = vec.begin(); it != vec.end(); i++) { cout << *it << " "; }   


## STL Algorithm
 - STL Algorithm은 iterator가 제공하는(or iterator에 의해 제공되는) 컨테이너 element 들의 시퀀스에서 작동함.   
 
 - 매우 많은 알고리즘과 그 변형들이 있음. cppreference.com과 같은 온라인에서 자세한 정보 얻을 수 있음.   
 
 - STL의 많은 알고리즘들은 사용하기 위해 프로그래머가 추가 정보를 제공해야함.    
 -> 3가지 방법으로 제공 가능.   
1. Functor(function object).   
2. Function pointer.    
3. Lamda expression(C++11).
    모던 c++에서는 람다를 사용하는 추세임.
    
 - #include <algorithm> 로 헤더파일 포함해주어야 함.
 
 - 컨테이너들은 각기 다른 타입의 알고리즘을 지원함.   
 -> 알고리즘은 iterator에 의존하기 때문에, iterator가 특정 컨테이너에 사용할 수 있는 알고리즘 타입을 결정함.   
+ 모든 알고리즘은 iterator가 인자로 들어옴. 인자로 들어오는 iterator가 컨테이너에서 얻어지는 시퀀스를 결정함.

- iterator invalidation   
iterator는 컨테이너의 요소를 가리킴.   
-> 처리되는 동안 이터레이터가 무효화 될 수 있음.   
ex) vector를 반복하는 도중에 clear()로 벡터 지워버린다면? iterator는 벡터가 지워진 것 모르기 때문에 반복이 계속됨(벡터의 끝에 도달할 때 까지).
그러나 이것은 더 이상 유효하지 않음.




