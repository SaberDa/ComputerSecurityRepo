import java.util.Scanner;

public class S_DES {
public static String key1;
public static String key2;
public static int[] IP = new int[] { 2, 6, 3, 1, 4, 8, 5, 7 };
public static int[] EP = new int[] { 4, 1, 2, 3, 2, 3, 4, 1 };
public static int[] P10 = new int[] { 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };
public static int[] P8 = new int[] { 6, 3, 7, 4, 8, 5, 10, 9 };
public static int[] P4 = new int[] { 2, 4, 3, 1 };
public static int[] IP_1 = new int[] { 4, 1, 3, 5, 7, 2, 8, 6 };
public static String[][] S1_box = new String[][] {
		{ "10", "01", "10", "01" }, { "10", "11", "11", "01" },
		{ "10", "11", "10", "10" }, { "10", "11", "01", "01" } };
public static String[][] S2_box = new String[][] {
		{ "01", "10", "11", "10" }, { "01", "10", "01", "10" },
        { "10", "10", "11", "00" }, { "11", "10", "11", "01" } };
        
public static String substitue(String str, int[] P) { 
	// make the substitue    
	StringBuilder sb = new StringBuilder();
	for (int i = 0; i < P.length; i++) {
		sb.append(str.charAt((P[i]) - 1));
	}
	return new String(sb);
}

public static String xor(String str, String key) { 
	// make the XOR
	StringBuilder sb = new StringBuilder();
	for (int i = 0; i < str.length(); i++) {
		if (str.charAt(i) == key.charAt(i)) {
			sb.append("0");
		} else {
			sb.append("1");
		}
	}
	return new String(sb);
}

public static String searchSbox(String str, int n) { 
	// Find in the S box
	StringBuilder sb = new StringBuilder();
	sb.append(str.charAt(0));
	sb.append(str.charAt(3));
	String ret = new String(sb);
	StringBuilder sb1 = new StringBuilder();
	sb1.append(str.charAt(1));
	sb1.append(str.charAt(2));
	String ret1 = new String(sb1);
	String retu = new String();
	if (n == 1) {
        retu = S1_box[Integer.parseInt(ret, 2)][Integer.parseInt(ret1, 2)];
        System.out.println("retu: " + retu);
	} else {
        retu = S2_box[Integer.parseInt(ret, 2)][Integer.parseInt(ret1, 2)];
        System.out.println("retu: " + retu);
	}
	return retu;
}

public static void getkey() { 
	// get Key1 and Key2
	System.out.println("-----Please input the key------");
	Scanner sc = new Scanner(System.in);
	String mainkey = sc.nextLine();
	mainkey = substitue(mainkey, P10);
	System.out.println("After permute 10: " + mainkey);
	String Ls11 = mainkey.substring(0, 5);
    Ls11 = move(Ls11, 1);
    System.out.println("After Move " + Ls11);
	String Ls12 = mainkey.substring(5, 10);
    Ls12 = move(Ls12, 1);
    System.out.println("After Move " + Ls12);
	key1 = Ls11 + Ls12;
	key1 = substitue(key1, P8);
	System.out.println("key1= " + key1);
	String Ls21 = move(Ls11, 2);
	String Ls22 = move(Ls12, 2);
	key2 = Ls21 + Ls22;
	key2 = substitue(key2, P8);
	System.out.println("key2= " + key2);
}

public static String move(String str, int n) { 
	// make the move, each step move 1 bit or 2 bits 
	char[] ch = str.toCharArray();
	char[] copy_ch = new char[5];
	for (int i = 0; i < ch.length; i++) {
		int a = ((i - n) % ch.length);
		if (a < 0) {
			if (n == 1) {
				copy_ch[ch.length - 1] = ch[i];
			}
			if (n == 2) {
				if (i == 0) {
					copy_ch[ch.length - 2] = ch[i];
				} else {
					copy_ch[ch.length - 1] = ch[i];
				}

			}
		} else {
			copy_ch[a] = ch[i];
		}
	}
	return new String(copy_ch);
}

public static void encrypt() { 
	// encrypt main body
	System.out.println("-----Please input the text------");
	Scanner sc = new Scanner(System.in);
	String plaintext = sc.nextLine();
	plaintext = substitue(plaintext, IP);
	System.out.println("After IP: " + plaintext);
	String L0 = plaintext.substring(0, 4);
	String R0 = plaintext.substring(4, 8);
	System.out.println("Right Half of IP: " + R0);
	System.out.println("Left Half of IP: " + L0);
	String R0E = substitue(R0, EP);
	System.out.println("Expansion Permutation: " + R0E);
	R0E = xor(R0E, key1);
	System.out.println("Key1 XOR: " + R0E);
	String S1 = R0E.substring(0, 4);
	String S2 = R0E.substring(4, 8);
	System.out.println("Left Half of XOR: " + S1);
	System.out.println("Right Half of XOR: " + S2);
	S1 = searchSbox(S1, 1);
	System.out.println("searchSbox S1: " + S1);
	S2 = searchSbox(S2, 2);
	System.out.println("searchSbox S2: " + S2);
	String SS = S1 + S2;
	System.out.println("Joio S-Box outputs: " + SS);
	String f1 = substitue(SS, P4);
	System.out.println("Permute 4: " + f1);
	String L1 = R0;
	String R1 = xor(f1, L0);
	System.out.println("XOR Left Half with F: " + R1);
    System.out.println("L1: " + L1);
    System.out.println("R1: " + R1);
	// We can get L1 and R1 here
	//-----------------The Second round-------------
	System.out.println("The second round");
	String R11 = substitue(R1, EP);
	System.out.println("EP: " + R11);
	R11 = xor(R11, key2);
	System.out.println("XOR with key2: " + R11);
	S1 = R11.substring(0, 4);
	System.out.println("Left Half of XOR: " + S1);
	S2 = R11.substring(4, 8);
	System.out.println("Right Half of XOR: " + S2);
	S1 = searchSbox(S1, 1);
	System.out.println("searchSbox S1: " + S1);
	S2 = searchSbox(S2, 2);
	System.out.println("searchSbox S2: " + S2);
	SS = S1 + S2;
	System.out.println("Joio S-Box outputs: " + SS);
	String f2 = substitue(SS, P4);
	System.out.println("Permute 4: " + f2);
	System.out.println("Left Half of SW: " + L1);
	String L2 = xor(f2, L1);
	System.out.println("XOR Left Half with F: " + L2);
	String R2 = R1;
	System.out.println("Left Half of SW: " + R2);
    System.out.println("L2: " + L2);
    System.out.println("R2: " + R2);
	//  We can get L1 and R1 here
	String ciphertext = L2 + R2;
	ciphertext = substitue(ciphertext, IP_1);
	System.out.println("Answer: " + ciphertext);
}

public static void main(String[] args) {
	getkey();
	encrypt();
 }
}
