import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static Map<Long, Boolean> vi = new HashMap<>();

    static class Calculation {
        private static final int MULTIPLY = 0;
        private static final int PLUS = 1;
        private static final int MINUS = 2;
        private static final int DIVISION = 3;

        public long result;
        public String operation;

        public Calculation(long result, String operation) {
            this.result = result;
            this.operation = operation;
        }

        public Boolean isVisited(int op) {
            if (result == 0) return false;
            switch (op) {
                case MULTIPLY:
                    return vi.get(result * result);
                case PLUS:
                    return vi.get(result + result);
                case MINUS:
                    return vi.get(result - result);
                case DIVISION:
                    return vi.get(result / result);
            }
            return false;
        }

        public Calculation caculate(int op) {
            Calculation tmp = new Calculation(this.result, this.operation);
            switch (op) {
                case MULTIPLY:
                    tmp.result *= tmp.result;
                    tmp.operation += "*";
                    break;
                case PLUS:
                    tmp.result += tmp.result;
                    tmp.operation += "+";
                    break;
                case MINUS:
                    tmp.result -= tmp.result;
                    tmp.operation += " -";
                    break;
                case 3:
                    if (tmp.result == 0) break;
                    tmp.result /= tmp.result;
                    tmp.operation += "/";
                    break;
            }
           return tmp;
        }
    };

    static Queue<Calculation> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        int givenNumber = Integer.parseInt(st.nextToken());
        int target = Integer.parseInt(st.nextToken());
        if (givenNumber == target) {
            bw.write("0" + "\n");
            bw.flush();
            return;
        }

        q.add(new Calculation(givenNumber, ""));
        Calculation answer = new Calculation(-1, "");
        int answerLength = 0;
        while (!q.isEmpty()) {
            Calculation calculation = q.poll();

            if (calculation.result <= 0) break;
            if (calculation.result == target) {
                answer.operation = calculation.operation;
                answer.result = target;
            }

            for (int i = 0; i < 4; i++) {
                if (calculation.isVisited(i) != null) continue;
                Calculation nextCalculation = calculation.caculate(i);
                vi.put(nextCalculation.result, true);
                if (nextCalculation.result == calculation.result
                        || nextCalculation.result == 0
                        || nextCalculation.result == givenNumber) continue;
                q.add(nextCalculation);
            }
        }

        if (answer.result != target) {
            bw.write("-1\n");
            bw.flush();
            return;
        }

        bw.write(answer.operation + "\n");
        bw.flush();
    }
}
