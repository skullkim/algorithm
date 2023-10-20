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

    static class Diff {
        public int value;
        public Ele ele1;
        public Ele ele2;

        public Diff(int value, Ele ele1, Ele ele2) {
            this.value = value;
            this.ele1 = ele1;
            this.ele2 = ele2;
        }

        @Override
        public boolean equals(Object obj) {
            return ((Diff)obj).value == this.value;
        }

        @Override
        public int hashCode() {
            return Objects.hash(value);
        }
    };

    public static int hasSameDiff(int[] candidate, Diff diff) {
        for (int i = 0; i < 3; i++) {
            if ((candidate[i] - diff.ele2.value) == diff.value) return i;
        }
        return -1;
    }

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

        Set<Diff> candidateDiffs = new HashSet<>();
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 3; k++) {
                int ele1 = candidates[0][i];
                int ele2 = candidates[1][k];
                candidateDiffs.add(new Diff(ele2 - ele1 , new Ele(ele1, 0), new Ele(ele2, 1)));
            }
        }

        boolean hasAns = false;
        if (sequenceLength <= 2) {
            bw.write("0\n");
            bw.flush();
            return;
        }
        for (Diff diff : candidateDiffs) {
            boolean isQualifiedDiff = true;
            int changed = 0;
//            if (diff.ele1.value == 0 && diff.value == 3) {
//                System.out.println(diff.ele2.value);
//            }
            if (diff.ele1.value != candidates[0][1]) changed++;
            if (diff.ele2.value != candidates[1][1]) changed++;
            for (int i = diff.ele2.index + 1; i < sequenceLength; i++) {
                int eleIdx = hasSameDiff(candidates[i], diff);
//                if (diff.value == 3) {
//                    System.out.println("e1: " + diff.ele1.value + ", e2: " + diff.ele2.value);
//                    System.out.println(eleIdx);
//                }
                if (eleIdx == -1) {
                    isQualifiedDiff = false;
                    break;
                } else{
                    diff.ele1 = diff.ele2;
                    diff.ele2 = new Ele(candidates[i][eleIdx], i);
                    if (eleIdx != 1) {
                        changed++;
                    }
                }
            }
            if (isQualifiedDiff) {
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
