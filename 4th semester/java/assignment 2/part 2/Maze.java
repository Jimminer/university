import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Maze {

    static char[][] Maze;

    static int startRow;
    static int startCol;

    static int[][] directions = {
        {0, 1}, // right
        {1, 0}, // down
        {0, -1}, // left
        {-1, 0} // up
    };

    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);

        System.out.print("\nMazes:\n1. 12x12\n2. 101x101\nPlease choose a maze: ");

        int choice = inp.nextInt();
        if (choice == 1){
            solve("input.txt");
        }
        else if (choice == 2){
            solve("input2.txt");
        }

        inp.close();
    }

    public static void solve(String fileName){
        System.out.println("\nReading maze from file " + fileName + ":");
        try{
            Scanner inp = new Scanner(new File("ask2/" + fileName));
            String[] temp;

            // Read maze size
            temp = inp.nextLine().split(", ");

            Maze = new char[Integer.parseInt(temp[0])][Integer.parseInt(temp[1])];

            System.out.println("Maze size: " + Maze.length + "x" + Maze[0].length);

            // Read maze entrance
            temp = inp.nextLine().split(", ");

            startRow = Integer.parseInt(temp[0]);
            startCol = Integer.parseInt(temp[1]);

            System.out.println("Entrance: " + startRow + "x" + startCol);

            for (int i = 0; i < Maze.length; i++) {
                String row = inp.next();
                for (int j = 0; j < Maze[0].length; j++) {
                    Maze[i][j] = row.charAt(j);
                }
            }

            inp.close();
        }
        catch (FileNotFoundException exception){
            System.out.println("File " + fileName + " not found!");
            return;
        }

        boolean[][] visited = new boolean[Maze.length][Maze[0].length];
        ArrayList<int[]> path = new ArrayList<int[]>();
        boolean found = traverse(startRow, startCol, visited, path);
        path.add(0, new int[] {startRow, startCol});
        if (found) {
            printMaze(path);
        } else {
            System.out.println("The maze could not be solved!");
        }
    }

    public static boolean traverse(int row, int col, boolean[][] visited, ArrayList<int[]> path) {
        // Check if we reached the end
        if ((row != startRow && col != startCol) && (Maze[row][col] == '.') && (row == 0 || row == Maze.length - 1 || col == 0 || col == Maze[0].length - 1)) {
            return true;
        }
        visited[row][col] = true;
        // Try all directions
        for (int[] direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];

            // Check if we are at a non visited valid position
            if (newRow >= 0 && newRow < Maze.length && newCol >= 0 && newCol < Maze[0].length && Maze[newRow][newCol] != '#' && !visited[newRow][newCol]) {
                if (traverse(newRow, newCol, visited, path)) {
                    // Save the correct path
                    path.add(0, new int[] {newRow, newCol});
                    return true;
                }
            }
        }
        return false;
    }

    public static void printMaze(ArrayList<int[]> path) {
        System.out.print("\n");
        for (int i = 0; i < Maze.length; i++) {

            for (int j = 0; j < Maze[0].length; j++) {
                boolean found = false;

                // Print the correct path represented by dots
                for (int[] step : path){
                    if (step[0] == i && step[1] == j){
                        System.out.print(". ");
                        found = true;
                        break;
                    }
                }
                if (found) continue;

                // Don't print dots when it is not in the path
                if (Maze[i][j] != '.'){
                    System.out.print("# ");
                    continue;
                }

                // Print the empty spaces
                System.out.print("  ");
            }
            System.out.println();

        }
    }
}
