import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int sequenceLength;
    static int answer = 987654321;

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
        
        if (sequenceLength <= 2) {
            bw.write("0\n");
            bw.flush();
            return;
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
                    ele2 += diff;
                    if (candidates[idx][1] == ele2) continue;
                    else if (candidates[idx][0] == ele2 || candidates[idx][2] == ele2) changed++;
                    else  {
                        hasAnswer = false;
                        break;
                    }
                }
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
