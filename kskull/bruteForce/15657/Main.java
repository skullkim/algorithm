import java.io.*;
import java.util.*;

public class Main {
    
    static ArrayList<Integer> arr = new ArrayList<>();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int numbers;
    static int length;

    static void f(ArrayList<Integer> al, int currIdx) throws IOException {
        if (al.size() == length) {
            for (int i = 0; i < length; i++) {
                bw.write(al.get(i) + " ");
            }
            bw.write("\n");
            return;
        }

        for (int i = currIdx; i < numbers; i++) {
            al.add(arr.get(i));
            f(al, i);
            al.remove(al.size() - 1);
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

        f(new ArrayList<>(), 0);
        bw.flush();
    }
}
