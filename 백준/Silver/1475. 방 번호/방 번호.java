import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String roomNum = sc.next();
		
		int[] set = new int[10];
		
		for(char c : roomNum.toCharArray()) {  
			int num = c - '0';
			if(num == 9) {  // 9와 6을 한 곳에 몰아넣기
				num = 6;
			}
			
			set[num]++;
		}
		
		// 6과 9를 한 곳에 넣었기 때문에 2로 나눠줌
		set[6] = set[6] / 2 + set[6] % 2;
		
		// 오름차순 정렬하고 마지막 요소가 답
		Arrays.sort(set);
		System.out.println(set[9]);
		
		sc.close();
	}
}