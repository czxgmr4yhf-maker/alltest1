import chat.*;
import thread.*;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        ChatRoom chatRoom = new ChatRoom();

        User u1 = new User("Alice");
        User u2 = new User("Bob");

        chatRoom.addUser(u1);
        chatRoom.addUser(u2);

        UserThread t1 = new UserThread(u1, chatRoom);
        UserThread t2 = new UserThread(u2, chatRoom);

        t1.start();
        t2.start();

        Scanner sc = new Scanner(System.in);

        while (true) {
            String input = sc.nextLine();
            // 模拟用户选择发送
            if (input.startsWith("1:")) {
                u1.sendMessage(chatRoom, input.substring(2));
            } else if (input.startsWith("2:")) {
                u2.sendMessage(chatRoom, input.substring(2));
            }
        }
    }    
}
