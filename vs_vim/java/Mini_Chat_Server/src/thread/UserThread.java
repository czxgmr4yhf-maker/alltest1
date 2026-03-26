package thread;

import chat.*;

public class UserThread extends Thread{
    private User user;
    private ChatRoom chatRoom;

    public UserThread(User user, ChatRoom chatRoom) {
        this.user = user;
        this.chatRoom = chatRoom;
    }

    @Override
    public void run() {
        while(true) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                break;
            }
        }
    }

    public User getUser() {
        return user;
    }
}
