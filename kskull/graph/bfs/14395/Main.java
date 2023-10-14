import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static class Calculation {
        public long result;
        public String operation;

        public Calculation(long result, String operation) {
            this.result = result;
            this.operation = operation;
        }

        public void removeLastOperation() {
            if (operation.length() >= 1) {
                operation = operation.substring(0, operation.length() - 1);
            }
        }

        public Calculation caculate(int op) {
            Calculation tmp = new Calculation(this.result, this.operation);
            switch (op) {
                case 0:
                    tmp.result += tmp.result;
                    tmp.operation += "+";
                    break;
                case 1:
                    tmp.result -= tmp.result;
                    tmp.operation += " -";
                    break;
                case 2:
                    tmp.result *= tmp.result;
                    tmp.operation += "*";
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
            if (calculation.result == target 
                    && (answer.result == -1 || answer.operation.compareTo(calculation.operation) > 0)
                    && (answer.operation.isBlank() || answer.operation.length() >= calculation.operation.length())) {
                answer.operation = calculation.operation;
                answer.result = target;
            }

            for (int i = 0; i < 4; i++) {
                Calculation nextCalculation = calculation.caculate(i);
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
