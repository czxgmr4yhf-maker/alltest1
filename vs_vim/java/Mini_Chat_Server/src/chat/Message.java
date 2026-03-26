package chat;

public class Message {
    private String sender; //发送者
    private String content; //发送内容

    public Message(String sender, String content) {
        this.sender = sender;
        this.content = content;
    }                       //构造方法

    @Override
    public String toString() {
        return sender + ":" + content;
    }
}
