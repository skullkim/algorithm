import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int questionNum;
    static int minDifficulty;
    static int maxDifficulty;
    static int difficultyDiff;
    static int answer = 0;
    static ArrayList<Integer> questiones = new ArrayList<>();

    static void selectQuestiones(ArrayList<Integer> selected, int difficulty, int idx) {
        if (idx > questionNum) return;


        if (selected.size() >= 2) {
//            System.out.println("diff: " + difficulty);
//            for (Integer a : selected) {
//                System.out.print(a + " ");
//            }
//            System.out.println();

            if (difficulty > maxDifficulty) return;

            if (difficulty >= minDifficulty) {
                int minD = 987654321;
                int maxD = 0;
                for (Integer question : selected) {
                    maxD = Math.max(maxD, question);
                    minD = Math.min(minD, question);
                }
//                System.out.println(maxD + ", " + minD);
//                System.out.println("===========");
                if (maxD - minD < difficultyDiff) return;
                
                answer++;
            }
        }


        for (int i = idx; i < questionNum; i++) {
            int question = questiones.get(i);
            selected.add(question);
            selectQuestiones(selected, difficulty + question, i + 1);
            selected.remove(selected.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        questionNum = Integer.parseInt(st.nextToken());
        minDifficulty = Integer.parseInt(st.nextToken());
        maxDifficulty = Integer.parseInt(st.nextToken());
        difficultyDiff = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < questionNum; i++) {
            questiones.add(Integer.parseInt(st.nextToken()));
        }

        selectQuestiones(new ArrayList<>(), 0, 0);

        bw.write(answer + "\n");
        bw.flush();
    }
}
