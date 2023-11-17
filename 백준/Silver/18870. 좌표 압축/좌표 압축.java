import java.util.*;

public class Main {
			// 좌표 압축 
	
			// 압축이라고 되어있지만 사실상 순위매기기..
	
			// 뭔가 정렬과 관련 되어 있을 것 같다
			// 근데 정렬 하기 전 배열도 필요하고, 정렬 된 배열도 필요할 것 같다
			// -> 둘 다 쓰자(배열 2개 선언)
			// 정렬된 배열에서 순위를 매겨야 하는데,, 순위는 0순위 부터 시작하니까
			// map구조를 이용해서 순위를 매기자
			
	
			// 접근
			// 1. 낮은 값이 높은 순위를 갖는다
			// 2. 중복되는 원소는 같은 순위를 가진다
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		int arr[] = new int[N];
		int arr_sorted[] = new int[N];
		HashMap<Integer, Integer> rankingMap = new HashMap<Integer, Integer>();
		
		for(int i = 0; i < N; i ++) {  
			arr_sorted[i] = arr[i] = sc.nextInt();
		}
		
		// 정렬 수행
		Arrays.sort(arr_sorted);
		
		// map에 넣어주기
		int rank = 0;
		for(int v : arr_sorted) {  
			// 이 때 만약 순위가 매겨져있다면
			// 중복되면 안되므로, 중복되지 않을 때만
			// 순위를 넣어준다
			
			if(!rankingMap.containsKey(v)) {  
				rankingMap.put(v, rank);
				rank ++;
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int key : arr) {  
			int ranking = rankingMap.get(key);
			sb.append(ranking).append(' ');
		}
		
		System.out.println(sb);
		
		sc.close();
	}

}