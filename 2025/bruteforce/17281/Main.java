import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int ONE = 1, TWO = 2, THREE = 3, HOME_RUN = 4, OUT = 0;
	
	static int[][] innings = new int[50][10];
	static int maxInnings, ans = -1;
	static boolean[] vi = new boolean[10];

	static void f(List<Integer> tmp) {
		if (tmp.size() == 9) {
			int tmpAns = 0;
			int currPlayerNum = 0, currIn = 0;

			int[] f = new int[10];
			while (currIn < maxInnings) {
				int out = 0;
				for (int i = 1; i <= 9; i++) f[i] = 0;

				while(true) {
					int currPlayer = tmp.get(currPlayerNum);
					int result = innings[currIn][currPlayer];
					if (out == 3) break;
					if (result == OUT) {
						out++; 
						currPlayerNum++;
						if (currPlayerNum >= 9) currPlayerNum = 0;
						
						continue;
					}

					if (result == ONE) {
						for (int i = 1; i <= 9; i++) {
							if (f[i] != 0) f[i] += 1;
							if (f[i] >= 4) {
								tmpAns++; f[i] = 0;
							}
						}
						f[currPlayer] = 1;
					} else if (result == TWO) {
						for (int i = 1; i <= 9; i++) {
							if (f[i] != 0) f[i] += 2;
							if (f[i] >= 4) {
								tmpAns++; f[i] = 0;
							}
						}
						f[currPlayer] = 2;
					} else if (result == THREE) {
						for (int i = 1; i <= 9; i++) {
							if (f[i] != 0) f[i] += 3;
							if (f[i] >= 4) {
								tmpAns++; f[i] = 0;
							}
						}
						f[currPlayer] = 3;
					} else if (result ==HOME_RUN) {
							int a = 0;
							for (int i = 1; i <= 9; i++) {
								if (f[i] != 0) {
									a++;
									f[i] = 0;
								}
							}
							tmpAns += (a + 1);
					}
					
					currPlayerNum++;
					if (currPlayerNum >= 9) currPlayerNum = 0;
				}

				currIn++;
			}

			ans = Math.max(tmpAns, ans);
			return;
		} 

		if (tmp.size() == 3) {
			tmp.add(1);
		}
		
		for (int i = 2; i <= 9; i++) {
			if (vi[i]) continue;
			tmp.add(i);
			vi[i] = true;
			f(tmp);
			vi[i] = false;
			tmp.remove(tmp.size() - 1);
		}

		if (tmp.size() == 4) {
			tmp.remove(tmp.size() - 1);
		}
	}
	
  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
		maxInnings = Integer.parseInt(st.nextToken());
		for (int i = 0; i < maxInnings; i++) {
			st = new StringTokenizer(br.readLine());
			for (int k = 1; k < 10; k++)  {
				innings[i][k] = Integer.parseInt(st.nextToken());
			}
		}

		vi[1] = true;
		f(new ArrayList<Integer>());
		bw.write(ans + "");
		bw.flush();
  }
}
