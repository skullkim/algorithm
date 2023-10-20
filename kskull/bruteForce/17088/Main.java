import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int sequenceLength;
    static ArrayList<Integer> sequence = new ArrayList<>();
    static int answer = 987654321;

    static void print(ArrayList<Integer> arr) {
        for (Integer a : arr) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    static boolean isAnswer(ArrayList<Integer> diffs) {
        int d = diffs.get(0);
        for (Integer diff : diffs) {
            if (d != diff) return false;
        }
        return true;
    }

    static ArrayList<Integer> changeDiff(int index, int number, ArrayList<Integer> diffs) {
        if (index == 0) {
            diffs.set(0, diffs.get(0) + number * (-1));
        } else if (index == sequenceLength - 1) {
            diffs.set(index - 1, diffs.get(index - 1) + number);
        } else {
            diffs.set(index, diffs.get(index) + number * (-1));
            diffs.set(index - 1, diffs.get(index - 1) + number);
        }
        return diffs;
    }

    static void findMin(int index, int operations, ArrayList<Integer> diffs) {
        if (index >= sequenceLength) return;
        if (isAnswer(diffs)) {
            answer = Math.min(answer, operations);
            return;
        }

        findMin(index + 1, operations, diffs);

        sequence.set(index, sequence.get(index) + 1);
        diffs = changeDiff(index, 1, diffs);
        findMin(index + 1, operations + 1, diffs);
        diffs = changeDiff(index, -1, diffs);
        sequence.set(index, sequence.get(index) - 1);

        sequence.set(index, sequence.get(index) - 1);
        diffs = changeDiff(index, -1, diffs);
        findMin(index + 1, operations + 1, diffs);
        diffs = changeDiff(index, 1, diffs);
        sequence.set(index, sequence.get(index) + 11);
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        sequenceLength = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < sequenceLength; i++) {
            sequence.add(Integer.parseInt(st.nextToken()));
        }
        ArrayList<Integer> diffs = new ArrayList<>();
        for (int i = 1; i < sequenceLength; i++) {
            int diff = sequence.get(i) - sequence.get(i - 1);
            diffs.add(diff);
        }

        findMin(0, 0, diffs);
        if (answer == 987654321) {
            bw.write("-1\n");
        } else {
            bw.write(answer + "\n");
        }
        bw.flush();
    }
}
