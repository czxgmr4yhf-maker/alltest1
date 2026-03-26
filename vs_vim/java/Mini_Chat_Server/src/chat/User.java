package chat;

public class User {
    private String username; //用户名
    private boolean online; //是否在线
    private int messageCount; //发送消息量
    // private Thread thread; //用户线程(多线程聊天室)

    public User(String username) {
        this.username = username;
        this.online = true;
        this.messageCount = 0;
    }                               //初始化

    public String getUsername() {
        return username;
    }

    public boolean isOnline() {
        return online;
    }

    public int getMessageCount() {
        return messageCount;
    }

    public void sendMessage(ChatRoom chatRoom, String content) {
        if(!online) {
            System.out.println("用户已经离线，无法发送消息");
            return;
        }
        chatRoom.broadcastMessage(this, content);
        messageCount++;
    }

    public void login() {
        this.online = true;
    }

    public void logout() {
        this.online = false;
    }

    @Override               //所有java默认继承Object，这个@重写Object中的toString函数
    public String toString() {
        return "User{" +
                "username='" + username + '\'' +
                ", online=" + online +
                ", messageCount=" + messageCount +
                '}';
    }
}
