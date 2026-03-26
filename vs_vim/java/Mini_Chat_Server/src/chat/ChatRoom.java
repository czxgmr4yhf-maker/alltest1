package chat;

import java.util.*;

public class ChatRoom {
    private Set<String> users = new HashSet<>();
    private List<Message> messages = new ArrayList<>();
    
    public void addUser(User user) {
        users.add(user.getUsername());
        System.out.println(user.getUsername() + "假如聊天室");
    }                                   //添加用户

    public void broadcastMessage(User user, String content) {
        Message msg = new Message(user.getUsername(), content);
        messages.add(msg);
        System.out.println(msg);
    }

    public void showUsers() {
        System.out.println("在线用户:");
        for (String user : users) {
            System.out.println(user);
        }
    }

    public void showHistory() {
        System.out.println("聊天记录:");
        for (Message msg : messages) {
            System.out.println(msg);
        }
    }
}
