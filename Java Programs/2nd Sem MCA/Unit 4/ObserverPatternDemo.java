import java.util.*;

// Observer Interface
interface Subscriber {
    void update(String videoTitle);
}

// Concrete Observer
class User implements Subscriber {
    String name;
    public User(String name) {
        this.name = name;
    }

    public void update(String videoTitle) {
        System.out.println(name + " got notification: " + videoTitle);
    }
}

// Subject (Publisher)
class YouTubeChannel {
    private List<Subscriber> subscribers = new ArrayList<>();

    public void subscribe(Subscriber s) {
        subscribers.add(s);
    }

    public void unsubscribe(Subscriber s) {
        subscribers.remove(s);
    }

    public void uploadNewVideo(String title) {
        System.out.println("New Video Uploaded: " + title);
        notifyAllSubscribers(title);
    }

    private void notifyAllSubscribers(String title) {
        for (Subscriber s : subscribers) {
            s.update(title);
        }
    }
}

// Main Class
public class ObserverPatternDemo {
    public static void main(String[] args) {
        YouTubeChannel channel = new YouTubeChannel();

        Subscriber u1 = new User("Alice");
        Subscriber u2 = new User("Bob");

        channel.subscribe(u1);
        channel.subscribe(u2);

        channel.uploadNewVideo("Design Patterns in Java");
    }
}
