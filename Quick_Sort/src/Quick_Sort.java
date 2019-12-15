import java.util.Random;

public class Quick_Sort {

	public static void QuickSort(int arr[], int start, int end) {
		
		if(start >= end) {
			return;
		}
		
		int pivot = arr[start];
		int Sloc = start;
		int Lloc = end;
		int temp;
		start++;
		
		while(start <= end) {
			
			while( start <= Lloc && pivot >= arr[start]  ) {
				start++;
			}
			
			while(Sloc < end && pivot <= arr[end]) {
				end--;
			}
			
			if(start < end) {
				temp = arr[start];
				arr[start] = arr[end];
				arr[end] = temp;
			}
			else if(start >= end) {
				
				arr[Sloc] = arr[end];
				arr[end] = pivot;
			}
			
		}
		
		for(int i = 0; i< arr.length; i++) {
			System.out.print(arr[i] + " ");
			}
		
		System.out.println("\n" +start + " " + end);
		
		QuickSort(arr, end+1 , Lloc);
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
