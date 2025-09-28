import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int ONE = 1, TWO = 2, THREE = 3, HOME_RUN = 4, OUT = 0;
	static class Field {
		int p; int num;
		public Field(int p, int num) {
			this.p = p; this.num = num;
		}
	}
	static int[][] innings = new int[50][10];
	static int maxInnings, ans = -1;
	static boolean[] vi = new boolean[10];

	static void f(List<Integer> tmp) {
		if (tmp.size() == 9) {
			int tmpAns = 0;
			int currPlayerNum = 0, currIn = 0;

			while (currIn < maxInnings) {
				int out = 0;
				List<Field> f = new ArrayList<>();

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
						for (int i = 0; i < f.size(); i++) {
							f.get(i).p += 1;
							if (f.get(i).p >= 4) {
								tmpAns++; f.remove(i); i--;
							}
						}
						f.add(new Field(1, currPlayer));
					} else if (result == TWO) {
						for (int i = 0; i < f.size(); i++) {
							f.get(i).p += 2;
							if (f.get(i).p >= 4) {
								tmpAns++; f.remove(i); i--;
							}
						}
						f.add(new Field(2, currPlayer));
					} else if (result == THREE) {
						for (int i = 0; i < f.size(); i++) {
							f.get(i).p += 3;
							if (f.get(i).p >= 4) {
								tmpAns++; f.remove(i); i--;
							}
						}
						f.add(new Field(3, currPlayer));
					} else if (result ==HOME_RUN) {
							tmpAns += (f.size() + 1);
							f.clear();
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
