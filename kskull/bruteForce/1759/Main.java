import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    
    static ArrayList<Character> vowels = new ArrayList<>();
    static ArrayList<Character> chars = new ArrayList<>();
    static int length;
    static int charNum;

    static {
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
    }

    static boolean isQualifiedPassword(ArrayList<Character> password) throws IOException {
        int vowelNum = 0;
        int otherCharNum = 0;
        for (Character c : password) {
            if (vowels.contains(c)) {
                vowelNum++;
                continue;
            }
            otherCharNum++;
        }
        return (vowelNum >= 1 && otherCharNum >= 2);
    }

    static void findAllPossibilities(ArrayList<Character> password, int currIdx) throws IOException {
        if (password.size() == length) {
            if (!isQualifiedPassword(password))  {
                return;
            }
            for (Character c : password) {
                bw.write(c);
            }
            bw.write("\n");
            return;
        }

        for (int i = currIdx; i < charNum; i++) {
            password.add(chars.get(i));
            findAllPossibilities(password, i + 1);
            password.remove(password.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        length = Integer.parseInt(st.nextToken());
        charNum = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < charNum; i++) {
            chars.add(st.nextToken().charAt(0));
        }
        Collections.sort(chars);
        findAllPossibilities(new ArrayList<>(), 0);
        bw.flush();
    }
}
