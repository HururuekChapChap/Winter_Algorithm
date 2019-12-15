import java.util.Random;

public class Quick_Sort {

	public static void QuickSort(int arr[], int start, int end) {
		
		//퀵정렬의 종료 부분 : 위치가 작거나 같다면 할 필요가 없다.
		if(start >= end) {
			return;
		}
		
		
		int pivot = arr[start];
		int Sloc = start;
		int Lloc = end;
		int temp;
		start++;
		
		while(start <= end) {
			
			// pivot 값이 arr[start] 값 보다 클 경우에 반복을 해준다. 즉, arr[start] 값이 pivot보다
			// 클 경우 반복문을 나간다. 이때, 오류났던 부분이 start <=Lloc 부분인데, 이부분을 먼저 써줘야한다.
			while( start <= Lloc && pivot >= arr[start]  ) {
				start++;
			}
			
			// 위에것과 마찬가지로 arr[end] 값이 pivot 보다 더 클경우에 반복을 해주고 pivot이 arr[end] 보다
			// 더 클경우는 작다는 의미이다.
			while(Sloc < end && pivot <= arr[end]) {
				end--;
			}
			
			//엇갈리지 않는다면 서로의 위치를 바꿔준다.
			if(start < end) {
				temp = arr[start];
				arr[start] = arr[end];
				arr[end] = temp;
			}
			
			//엇갈린다면 처음 위치에 end 값을 넣어주고 end 값에 pivot 값을 넣어준다.
			else if(start >= end) {
				
				arr[Sloc] = arr[end];
				arr[end] = pivot;
			}
			
		}
		
		for(int i = 0; i< arr.length; i++) {
			System.out.print(arr[i] + " ");
			}
		
		System.out.println("\n" +start + " " + end);
		
		// 여기서 부터 분활을 하는
		// 마지막 end값을 기준이로 한칸 뒷 부분 
		QuickSort(arr, end+1 , Lloc);
		// 마지막 end값을 기준으로 한칸 앞 부분으로 나눤다.
		// 처음에 quick_sort를 잘 못 이해해서, end 값을 그대로 써줬는데, 아니였다.
		QuickSort(arr, Sloc, end-1);
		
		
		
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int Array[] = new int[10];//{2,2,1,6,2,0,7,9,6,9};
	
		Random rand = new Random();
		for(int i = 0; i< 10; i++) {
			Array[i] = rand.nextInt(10);
			System.out.print(Array[i]);
		}
		
		System.out.println(" start ");
		QuickSort(Array,0,Array.length-1);
		
		
	}

}
