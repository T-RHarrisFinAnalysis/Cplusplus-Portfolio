/*

Created by Tim Harris
CS-250 Module Three - Basic ListView Control Project
Image Sources:
Destination images obtained from Wikimedia Commons.
*/

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Hyperlink;
import javafx.scene.control.Label;
import javafx.scene.control.ListCell;
import javafx.scene.control.ListView;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.awt.Desktop;
import java.net.URI;

public class BasicListViewControl extends Application {

    @Override
    public void start(Stage primaryStage) {

        // Label with creator's name
        Label creatorLabel = new Label("Created by Tim Harris");
        creatorLabel.setStyle("-fx-font-size: 16px; -fx-font-weight: bold; -fx-padding: 10;");

        // Create ListView
        ListView<Destination> listView = new ListView<>();

        // Add top five destinations
        listView.getItems().addAll(

                new Destination(
                        "Adirondack Adventure",
                        "Explore mountain trails and serene lakes in the Adirondacks, perfect for nature lovers and hikers.",
                        "/images/Aderon.jpg",
                        "https://www.expedia.com/"),

                new Destination(
                        "Western Cowboy Experience",
                        "Experience authentic cowboy culture with ranch stays, horseback riding, and rodeos in the American West.",
                        "/images/WesternGetaway.jpg",
                        "https://www.expedia.com/"),

                new Destination(
                        "Bahamas Beach Paradise",
                        "Relax on pristine white sand beaches and enjoy crystal-clear waters in the Bahamas’ tropical paradise.",
                        "/images/BahamaGetaway.jpg",
                        "https://www.expedia.com/"),

                new Destination(
                        "Kyoto & Okinawa, Japan",
                        "Discover Japan’s rich culture with historic temples in Kyoto and stunning beaches in Okinawa.",
                        "/images/okinawa_kyoto.jpg",
                        "https://www.expedia.com/"),

                new Destination(
                        "Southeast Asian Hotspot",
                        "Visit vibrant markets, beautiful temples, and exotic beaches in destinations like Bali and Thailand.",
                        "/images/SouthEastAsia.jpg",
                        "https://www.expedia.com/"));

        // Customize ListView cells
        listView.setCellFactory(param -> new ListCell<Destination>() {

            // Display image for each destination
            private ImageView imageView = new ImageView();

            // Destination title label
            private Label nameLabel = new Label();

            // Destination description label
            private Label descLabel = new Label();

            // Clickable booking link
            private Hyperlink bookingLink = new Hyperlink("View Packages");

            // Layout containers
            private VBox vbox = new VBox(nameLabel, descLabel, bookingLink);
            private HBox hbox = new HBox(imageView, vbox);

            {
                // Configure image size
                imageView.setFitWidth(120);
                imageView.setFitHeight(90);
                imageView.setPreserveRatio(true);

                // Spacing and padding
                vbox.setSpacing(5);
                vbox.setPadding(new Insets(0, 0, 0, 10));

                // Style destination title
                nameLabel.setStyle("-fx-font-size: 14px; -fx-font-weight: bold;");

                // Enable text wrapping
                descLabel.setWrapText(true);
                descLabel.setMaxWidth(300);

                // Align content
                hbox.setAlignment(Pos.CENTER_LEFT);
                hbox.setSpacing(10);

                // Open booking webpage when hyperlink is clicked
                bookingLink.setOnAction(e -> {
                    Destination d = getItem();

                    if (d != null) {
                        openWebpage(d.bookingUrl);
                    }
                });
            }

            @Override
            protected void updateItem(Destination dest, boolean empty) {
                super.updateItem(dest, empty);

                if (empty || dest == null) {
                    setGraphic(null);
                    setText(null);
                } else {

                    // Load destination image
                    imageView.setImage(
                            new Image(
                                    getClass().getResourceAsStream(dest.imageUrl)));

                    // Set destination text
                    nameLabel.setText(dest.name);
                    descLabel.setText(dest.description);

                    setText(null);
                    setGraphic(hbox);
                }
            }
        });

        // Main layout
        VBox root = new VBox(10, creatorLabel, listView);
        root.setPadding(new Insets(10));

        // Scene setup
        Scene scene = new Scene(root, 700, 600);

        primaryStage.setTitle("Top Five Travel Destinations");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    // Open webpage in browser
    private void openWebpage(String url) {
        try {
            Desktop.getDesktop().browse(new URI(url));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Destination class
    public static class Destination {

        String name;
        String description;
        String imageUrl;
        String bookingUrl;

        public Destination(String name, String description,
                String imageUrl, String bookingUrl) {

            this.name = name;
            this.description = description;
            this.imageUrl = imageUrl;
            this.bookingUrl = bookingUrl;
        }
    }

    public static void main(String[] args) {
        launch(args);
    }

}