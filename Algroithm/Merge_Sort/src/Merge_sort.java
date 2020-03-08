import java.util.Random;

public class Merge_sort {
	
	
	static int temp[] = new int[10];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
		Random rand = new Random();
		int Array[] = new int[10];
		
		//랜덤 값으로 배열에 넣어준다.
		for(int i = 0; i<10; i++) {
			Array[i] = rand.nextInt(10);
			System.out.print(Array[i] + " ");
		}
		
		//분할을 해준다.
		Split_Merge(Array,0, Array.length-1);
		
		System.out.println(" ");
		
		// 이렇게 모든 수행을 마치고 나면 N * log N이라는 시간 복잡도가 나온다.
		for(int i = 0; i<Array.length; i++) {
			System.out.print(Array[i] + " ");
		}
	}
	
	public static void Split_Merge(int arr[], int start, int end) {
		
		// start <= end 값으로 하면  0 0일 경우 계속 들어가서 안된다.
		if(start < end) {
			
			//System.out.println(start + " " + end);
			
			// 중앙 값을 주고 먼저 나눠주고 마지막에 하나씩 처리 해준다. 재귀는 스택 방식으로 수행 한다는거! 그래서
			// 가장 낱게의 것들이 먼저 합쳐진다. 이것이 재귀의 핵심!
			int middle = (start +end )/2;
			Split_Merge(arr, middle + 1 , end);
			Split_Merge(arr,start, middle);
			// 합쳐준다.
			Merge(arr,start, middle, end);
		}
		
	}
	
	public static void Merge(int arr[], int start, int middle, int end ) {
		
		int left = start;
		int right = middle + 1;
		int temp_loc = start;
		
		// left가 middle이 되기 전까지 또는 right가 end가 되기 전까지
		// 서로 비교하면서 둘중에 더 작은 값이 전역변수로 선언된 temp에 들어가게 된다.
		while(left <= middle && right <= end) {
			
			if(arr[left] < arr[right]) {
				temp[temp_loc] = arr[left];
				left++;
			}
			else {
				temp[temp_loc] = arr[right];
				right++;
			}
			
			temp_loc++;
			
		}
		
		
		// 그리고 나머지 부분은 큰 값이니, 나머지 부분을 넣어주고.
		if(left > middle ) {
			
			for(;right <=end; right++) {
				temp[temp_loc] = arr[right];
				temp_loc++;
			}
			
		}
		else if(right > end){
			
			for(;left <= middle; left++) {
				temp[temp_loc] = arr[left];
				temp_loc++;
			}
			
		}
		
		
		//temp는 임시 저장소 이기 때문에, 다시 arr에 넣어줘서 정렬을 해준다.
		for(int i = start; i<=end; i++) {
			arr[i] = temp[i];
		}
		
		
	}

}
