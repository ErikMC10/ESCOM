package turingmachine;

import java.util.Scanner;

public class TuringMachine {

    private static final int constant = 100;
    public static void main(String[] args) {
        
        boolean flag = true;
        
        while(flag){
            Scanner scanner = new Scanner(System.in);
            System.out.println("\n\n\nM�quina de Turing");
            System.out.println("Elige una opci�n");
            System.out.println("\n1.Entrada estandar");
            System.out.println("2.Cadena aleatoria");
            System.out.println("3.Leer archivo");
            System.out.println("4.Salir");
            System.out.print(" -> ");
            switch(scanner.nextInt()){
                case 1:
                    scanner.nextLine();
                    System.out.println("Digita una cadena binaria");
                    new Machine().standardInput(scanner.nextLine(), 0);
                    break;
                case 2:
                    scanner.nextLine();
                    new Machine().standardInput(randomString(), 0);
                    break;
                case 3:
                    scanner.nextLine();
                    System.out.println("Escribe la ruta del archivo que voy a leer.");
                    new Machine().readByKeyboard(scanner.nextLine());
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Esa opci�n no existe");
                    break;
            }
        }
    }
    
    public static String randomString(){
        String str = "";
        for(int i = 0; i < (int)(Math.random()*constant); i++){
            str += (int)(Math.rint(Math.random()));
        }
        System.out.println("El sistema gener� la cadena: " + str);
        return str;
    }   
}
