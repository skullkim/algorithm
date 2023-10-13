import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static final int MAX_PEOPLE = 21;
    static int people;
    static int[][] graph = new int[MAX_PEOPLE][MAX_PEOPLE];
    static int minDiff = 987654321;

    static int calculateAbility(ArrayList<Integer> team) {
        int sum = 0;
        for (int i = 0; i < team.size(); i++) {
            for (int k = 0; k < team.size(); k++) {
                sum += graph[team.get(i)][team.get(k)];
            }
        }
        return sum;
    }

    static ArrayList<Integer> generateAnotherTeam(ArrayList<Integer> team) {
        ArrayList<Integer> anotherTeam = new ArrayList<>();
        for (int i = 0; i < people; i++) {
            if (team.contains(i)) continue;
            anotherTeam.add(i);
        }
        return anotherTeam;
    }

    static void print(ArrayList<Integer> a) throws IOException {
        for (Integer aa : a) {
            bw.write(aa + " ");
        }
        bw.write("\n");
    }

    static void calculatePosibilities(int currPerson, ArrayList<Integer> team, int teamSize) throws IOException {
        if (team.size() == teamSize) {
            minDiff = Math.min(minDiff, Math.abs(calculateAbility(team) - calculateAbility(generateAnotherTeam(team))));
            return;
        }

        for (int i = currPerson; i < people; i++) {
            team.add(i);
            calculatePosibilities(i + 1, team, teamSize);
            team.remove(team.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        people = Integer.parseInt(st.nextToken());
        for (int i = 0; i < people; i++) {
            st = new StringTokenizer(br.readLine());
            for (int k = 0; k < people; k++) {
                graph[i][k] = Integer.parseInt(st.nextToken());
            }
        }

//        for (int i =0; i < people; i++) {
//            for (int k = 0; k < people; k++) {
//                bw.write(graph[i][k] + " ");
//            }
//            bw.write("\n");
//        }
//        bw.write("\n");

        calculatePosibilities(0, new ArrayList<>(), people / 2);

        bw.write(minDiff + "\n");
        bw.flush();
    }
}
