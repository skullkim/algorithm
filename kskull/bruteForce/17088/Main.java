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

        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 3; k++) {
                int ele1 = candidates[0][i];
                int ele2 = candidates[1][k];
                int diff = ele2 - ele1;
                int changed = 0;
                if (i != 1) changed++;
                if (k != 1) changed++;
                boolean hasAnswer = true;
                for (int idx = 2; idx < sequenceLength; idx++) {
//                    System.out.println(ele2 + ", " + idx + ", " + diff + ", " + (ele2 + diff));
//                    for (int ii = 0; ii < 3; ii++) {
//                        System.out.print(candidates[idx][ii] + " ");
//                    }
//                    System.out.println();
//                    System.out.println("=====================");
                    ele2 += diff;
                    if (candidates[idx][1] == ele2) continue;
                    else if (candidates[idx][0] == ele2 || candidates[idx][2] == ele2) changed++;
                    else  {
                        hasAnswer = false;
                        break;
                    }
                }
 //               System.out.println("diff: " + diff + ", " + changed + ", " + hasAnswer);
                if (hasAnswer) {
                    answer = Math.min(answer, changed);
                } 
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
