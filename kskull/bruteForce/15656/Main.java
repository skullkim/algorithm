import java.io.*;
import java.util.*;

public class Main {

    static ArrayList<Integer> arr = new ArrayList<>();
    static int numbers;
    static int length;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static void f(ArrayList<Integer> answer) throws IOException {
        if (answer.size() == length) {
            for (int i = 0 ; i < answer.size(); i++) {
                bw.write(answer.get(i) + " ");
            }
            bw.write("\n");
            return;
        }


        for (int i = 0; i < numbers; i++) {
            answer.add(arr.get(i));
            f(answer);
            answer.remove(answer.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        numbers = Integer.parseInt(st.nextToken());
        length = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < numbers; i++) {
            arr.add(Integer.parseInt(st.nextToken()));
        }

        Collections.sort(arr);
        
        f(new ArrayList<Integer>());

        bw.flush();
    }
}
