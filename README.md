# Winter_Algorithm
 그냥 겨울방학 알고리즘 공부

# 개요
 겨울방학을 시작해서 알고리즘 기초를 복습하고 문제해결 기법을 기르는 시간과 간단한 프로젝트를 한 것이 이번 방학의 목표이다.

# 2019.12.15
 오랜만에 Bubble정렬과 삽입 정렬에 대해서 닷 코들 적어보고 복습하는 시간을 가졌다. (Sort_Basic)
 백준에서 정렬 문제인 보물 문제(1026) 문제를 풀었다. (Treasure_1026)
 백준에서 정렬 문제인 좌표정렬 문제(11650) 문제를 풀었다. (Coordinate-11650)
 자바로 정렬으 기본은 Quick_Sort에 대해 다시 공부하고 구현으 해봤다. 오랜만에 해서 구현에 애먹었다 ㅠㅠ. 확실히 분할의 기본이라 생각된다. (Quick_Sort) 
 
 # 2019.12.16
 
 백준에서 정려 문제인 좌표정렬하기2(coordinat-11651)와 나이순 정렬(Sort_Of_Age - 10814)를 풀었다. quick_Sort로 정렬하는 sort STL과 달리 
 merge_Sort로 정렬하는 stable_sort를 알았다. 아직 실질적이 속도차이르 느끼지 못했지만, 어제와 다른 정렬 STL인 stable_Sort로 풀어서 경험은 했다.

 Merge_Sort에 대한 구현을 자바로 하였다. Merge_Sort는 Quick_Sort와는 다르게 항상 N *logN이라는 시간 복잡도를 가지고 있다. 왜냐하면 Quick_Sort는 정렬이          된 상태 이 경우 처음 부터 끝까지 확인하고 앞 부분 나눠주고 다시 끝까지 확인하고 앞 부부 나눠주고 이럴 경우에, N *N 이라는 시간 복잡도를 가지게 된다. 반면에.  Merge_Sort는 일단 나눠주고 정렬 관계오 상관없이 merge 부분에서 비교를 통하여 넣어준다. 이 부분이 N이라는 시간을 가지고 나눠줄 때, logN이라는 시간을 가진다. 따. 라서 N * logN이라는 시간을 가직 되는 것이다. 하지만 이렇게 정렬된 상태에서는 삽입정렬이 좋다. 많은 탐색을 하지 않기 때문에 N이라는 시가 복잡도에 가까워 질 수 있다. 

# 2019.12.17 ~ 19.12.18

백준에서 정려 문제 k 번째 수(NumberK-11004) 와 욕심쟁이 판다(Greedy_Panda-1937) 그리고 국영수 (Korea_English_Math-10825) 문제를 풀었다. 이 주 욕심쟁이 판다는 정렬 문제로 알 풀려고 했는데, 아직 이 문젝 왜 정렬 문제 인지 이해가 안된다. 나는 DFS와 DP를 활용해서 풀었다. 결과를 정렬하는 것도 쓰지 않았고, 정렬 기법을 쓰지 않았지만, 정렬 문제로 분류돼서 당황스럽다. 한번 알아봐야겠다.

# 2019.12.18

백준에서 카드 문제(Card-11652)와 ABC(ABC-3047) 문제를 풀었다. ABC문제는 그냥 신박했다. 반면 카드 문제는 색다른 탐색 방법 같은 느낌이라서 도움이 됐다.

힙정렬에 대해서 공부했다. 이로서 정렬의 거의 끝으 보고 있다. 힙정렬은 거의 다른 빠른 정렬(퀵소드, 합병)과 비슷한 N * log N이라는 시간 복잡도를 가지고 있다. 그런데 정렬을 하는 과정에서 모든 원소를 다 힙 정렬을 하는 것은 아니다. 예를 들어 마지마 리프 노드에 해당하는 부분으 하지 않는다. 따라서 N 보다는 느릭 N*logN 보다 빠르 시가 복잡도가 나온다고 한다. logN은 힙이 완전 이진 트리구조 이기 때문에, 빠르게 아래로 내려가 수 있다.자세한 내용은 코드에 있다. 힙정렬에 대한 이론에 대해서 공부하였기 때문에, 앞으로 더 심화된 내용을 이해 해보려고 하겠다.

# 2019.12.19 ~ 2019.12.20

백준에서 전화 번호 목록(Phone_Number_List - 5052)와 수열 정렬 (Sequence_Sort - 1015)를 풀었다. 둘다 저번과 달리 생각을 필욜 하는 문제였다. 정렬 문제는 뭔가 꼬의면 어려워진다는게, 어렵다. 전화 번호 목록 문제 같은 경우 처음에 굉장히 어거지로 어렵게 풀었다. 문제의 해설을 보면 알 수 있는데, 정말 운이 좋게 통과를 했다. 그래서 다른 사람의 코드르 보니, 트라이 알고리즘을 사용하여 푼 사람도 있었고 sort의 기능을 이용해서 푼 사람도 있었다. sort 알고리즘이 문자열이 경우에 비슷한 것을 모아주는 기능이 있어서, 굉장히 쉽게 풀 수 있는 문제 였다느 것을 알았고. 또 수열 정려 문제는 일단 문제 자체를 이해하기 어려웠다. 그래서 생각을 하다가 스스로 굉장히 헷갈렸다. 그래도 오늘도 무사히 두문제를 넘겼다.

계수 정렬에 대해서 공부를 했다. 계수 정렬은 다른 정렬 처럼 위치를 바꾸는 정렬이 아니라 Counting 정렬이다. Counting을 한다는 것은 숫자를 세는 것이다. 따라서 숫자를 읽고 그것을 다르 배열에 넣어준다. 동일하 값이 나온다면 넣어준 배열의 위치의 값을 하나 증가시켜준다. 계수정렬은 이렇게 카운트를 해서 그 위치를 갯수 만큼 출력해주는 알고리즘 이기 때문에, N이라는 시가 복잡도를 가지고 있다. 따라서 탐색고 정렬 모두 굉장히 빠르다. 하지만 계수정렬은 저장될 최대 숫자를 알아야하기 때문에 유동적이지 않고 고정적이기 때문에, 사용하기에는 좀 부족하 방식이다.



