package Automata;


public class Alphabet {
    
    /**This function return true if the character is part of
     our alphabet**/
    public boolean isPart(char character){
        return (((int)character >= 65 || (int)character <= 90) && ((int)character > 97 || (int)character <= 122 ));
    }
    
    public boolean isA(char character) {
        return (character == 'a' || character == '�' || character == '�' || character == '�'
                || character == 'A' || character == '�' || character == '�' || character == '�');
    }

    public boolean isB(char character) {
        return (character == 'b' || character == 'B');
    }

    public boolean isC(char character) {
        return (character == 'c' || character == 'C');
    }

    public boolean isD(char character) {
        return (character == 'd' || character == 'D');
    }

    public boolean isE(char character) {
        return (character == 'e' || character == '�' || character == '�' || character == '�'
                || character == 'E' || character == '�' || character == '�' || character == '�');
    }

    public boolean isF(char character) {
        return (character == 'f' || character == 'F');
    }

    public boolean isG(char character) {
        return (character == 'g' || character == 'G');
    }

    public boolean isH(char character) {
        return (character == 'h' || character == 'H');
    }

    public boolean isI(char character) {
        return (character == 'i' || character == '�' || character == '�' || character == '�'
                || character == 'I' || character == '�' || character == '�' || character == '�');
    }

    public boolean isJ(char character) {
        return (character == 'j' || character == 'J');
    }

    public boolean isK(char character) {
        return (character == 'k' || character == 'K');
    }

    public boolean isL(char character) {
        return (character == 'l' || character == 'L');
    }

    public boolean isM(char character) {
        return (character == 'm' || character == 'M');
    }

    public boolean isN(char character) {
        return (character == 'n' || character == 'N');
    }

    public boolean is�(char character) {
        return (character == '�' || character == '�');
    }

    public boolean isO(char character) {
        return (character == 'o' || character == '�' || character == '�' || character == '�'
                || character == 'O' || character == '�' || character == '�' || character == '�');
    }

    public boolean isP(char character) {
        return (character == 'p' || character == 'P');
    }

    public boolean isQ(char character) {
        return (character == 'q' || character == 'Q');
    }

    public boolean isR(char character) {
        return (character == 'r' || character == 'R');
    }

    public boolean isS(char character) {
        return (character == 's' || character == 'S');
    }

    public boolean isT(char character) {
        return (character == 't' || character == 'T');
    }

    public boolean isU(char character) {
        return (character == 'u' || character == '�' || character == '�' || character == '�'
                || character == 'U' || character == '�' || character == '�' || character == '�');
    }

    public boolean isV(char character) {
        return (character == 'v' || character == 'V');
    }

    public boolean isW(char character) {
        return (character == 'w' || character == 'W');
    }

    public boolean isX(char character) {
        return (character == 'x' || character == 'X');
    }

    public boolean isY(char character) {
        return (character == 'y' || character == 'Y');
    }

    public boolean isZ(char character) {
        return (character == 'z' || character == 'Z');
    }
}
