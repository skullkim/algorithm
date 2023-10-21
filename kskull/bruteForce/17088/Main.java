import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int sequenceLength;
    static int answer = 987654321;

    static class Ele {
        public int value;
        public int index;
    
        public Ele(int value, int index) {
            this.value = value;
            this.index = index;
        }
    };


    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        sequenceLength = Integer.parseInt(st.nextToken());

        int[][] candidates = new int[sequenceLength][3];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < sequenceLength; i++) {
            int number = Integer.parseInt(st.nextToken());
            candidates[i][0] = number - 1;
            candidates[i][1] = number;
            candidates[i][2] = number + 1;
        }

        Set<Integer> candidateDiffs = new HashSet<>();
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 3; k++) {
                int ele1 = candidates[0][i];
                int ele2 = candidates[1][k];
                candidateDiffs.add(ele2 - ele1);
            }
        }

        for (Integer diff : candidateDiffs) {
            boolean isAns = true;
            int changed = 0;
            int lastEle = -1;
            for (int idx = 1; idx < sequenceLength; idx++) {
                boolean hasDiff = false;
                int c = 10;
                int le = -1;
                for (int i = 0; i < 3; i++) {
                    int ele1 = candidates[idx - 1][i];
                    for (int k = 0; k < 3; k++) {
                        int cc = 0;
                        int ele2 = candidates[idx][k];
                        if ((ele2 - ele1) == diff && (lastEle == -1 || lastEle == ele1)) {
                            if (idx == 1) {
                                if (i != 1) cc++;
                                if (k != 1) cc++;
                            } else {
                                if (k != 1) cc++;
                            }

                            if (cc < c) {
                                c = cc;
                                le = ele2;
                            }
                            hasDiff = true;
                        }
                    }
                }
                lastEle = le;
                if (!hasDiff) {
                    isAns = false;
                    break;
                } else {
                    changed += c;
                }
            }
            if (isAns) {
                answer = Math.min(answer, changed);
            }
        }

        
        if (answer == 987654321) {
            bw.write("-1\n");
        } else {
            bw.write(answer + "\n");
        }
        bw.flush();
    }
}
