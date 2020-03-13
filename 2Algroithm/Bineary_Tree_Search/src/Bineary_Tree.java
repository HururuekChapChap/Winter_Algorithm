import java.util.Random;
import java.util.Scanner;

class Node{
	
 int data;
 Node left;
 Node right;
 
 Node(){
	 left = null;
	 right = null;
 }
 
 public void setNode(int data) {
	 this.data = data;
	 this.left = null;
	 this.right = null;
 }
 
 public int getNode() {
	 return data;
 }
	
}


public class Bineary_Tree {

	static Node root = null;
	
	Bineary_Tree(){}
	
	static Node insert(Node root, int data) {
		Node parent = root;
		Node new_node = new Node();
		new_node.setNode(data);
		
		if(parent == null) {
			//보내준 노드가 없다면 그 위치에 입력을 해준다.
			parent = new_node;
		}
		else if(parent.data > new_node.data) {
			//현재 데이터 값 보다 새로운 노드값이 더 작다면 왼쪽으로 보내준다.
			//내가 처음에 그냥 parent = insert(..)이렇게 해줬는데, 이렇게 하면 parent가 parent.left의 값을
			//받아버려서 안된다. 따라서 정확히 parent.left로 지정을 해줘야한다!.
			parent.left = insert(parent.left, data);
		}
		else if(parent.data < new_node.data) {
			//현재 데이터 값 보다 새로운 노드 값이 더 크다면 오른쪽으로 보내준다.
			parent.right = insert(parent.right, data);
		}
		
		return parent;
		
	}
	
	public static void inorder_Print(Node node) {
		if(node != null) {
			inorder_Print(node.left);
			System.out.print(node.data +" ");
			inorder_Print(node.right);
		}
	}
	
	public static void preorder_Print(Node node) {
		if(node != null) {
			System.out.print(node.data +" ");
			preorder_Print(node.left);
			preorder_Print(node.right);
		}
	}
	public static void postorder_Print(Node node) {
		if(node != null) {
			postorder_Print(node.left);
			postorder_Print(node.right);
			System.out.print(node.data +" ");
		}
	}
	
	//그 값이 존재하는지 않하는지 확인해준다.
	public static boolean Bineary_Search(Node node, int item) {
		
		boolean flag = false;
		
		while(node != null) {
			
			if(node.data < item) {
				node = node.right;
			}
			else if(node.data > item) {
				node = node.left;
			}
			else if(node.data == item) {
				flag = true;
				break;
			}
			
		}
		
		return flag;
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		Random rand = new Random();
		int N = scan.nextInt();
		
	
		for(int i = 1; i<= N; i++) {
			int item = rand.nextInt(100);
			if(!Bineary_Search(root,item ) ) {
				System.out.print(item +" ");
				root = insert(root,item);
			}
			else {
				System.out.print("\n"+item +"이 존재하여 다시!");
				i--;
			}
			
		}
		
		System.out.println("\n중위순회");
		
		inorder_Print(root);
		
		System.out.println("\n전위순회");
		
		preorder_Print(root);
		
		System.out.println("\n후위순회");
		
		postorder_Print(root);
		
	}

}
