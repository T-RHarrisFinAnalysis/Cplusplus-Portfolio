/*
 * Name: Tim Harris
 * Date: [May 31 2026]
 * Project: Detox and Wellness Travel Slideshow
 */

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class SlideShow extends JFrame {

    private JPanel slidePane;
    private JPanel textPane;
    private JPanel buttonPane;

    private CardLayout card;
    private CardLayout cardText;

    private JButton btnPrev;
    private JButton btnNext;

    public SlideShow() {
        initComponents();
    }

    private void initComponents() {

        card = new CardLayout();
        cardText = new CardLayout();

        slidePane = new JPanel();
        textPane = new JPanel();
        buttonPane = new JPanel();

        btnPrev = new JButton("Previous");
        btnNext = new JButton("Next");

        setTitle("Top 5 Detox and Wellness Travel Destinations");
        setSize(900, 700);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        slidePane.setLayout(card);
        textPane.setLayout(cardText);

        for (int i = 1; i <= 5; i++) {

            JLabel imageLabel = createImageLabel(i);
            JLabel textLabel = new JLabel(getTextDescription(i), JLabel.CENTER);

            slidePane.add(imageLabel, "slide" + i);
            textPane.add(textLabel, "text" + i);
        }

        btnPrev.addActionListener(e -> goPrevious());
        btnNext.addActionListener(e -> goNext());

        buttonPane.setLayout(new FlowLayout());
        buttonPane.add(btnPrev);
        buttonPane.add(btnNext);

        add(textPane, BorderLayout.NORTH);
        add(slidePane, BorderLayout.CENTER);
        add(buttonPane, BorderLayout.SOUTH);
    }

    private JLabel createImageLabel(int i) {

        String fileName = "";

        switch (i) {
            case 1:
                fileName = "resources/BaliYoga.jpg";
                break;
            case 2:
                fileName = "resources/SedonaSpaEscape.jpg";
                break;
            case 3:
                fileName = "resources/CostaRicaWellness.jpg";
                break;
            case 4:
                fileName = "resources/ThailandDetoxSanctuary.jpg";
                break;
            case 5:
                fileName = "resources/IcelandGeothermalSpa.jpg";
                break;
        }

        ImageIcon icon = new ImageIcon(fileName);

        Image scaledImage =
                icon.getImage().getScaledInstance(
                        700,
                        450,
                        Image.SCALE_SMOOTH);

        return new JLabel(new ImageIcon(scaledImage));
    }

    private void goPrevious() {
        card.previous(slidePane);
        cardText.previous(textPane);
    }

    private void goNext() {
        card.next(slidePane);
        cardText.next(textPane);
    }

    private String getTextDescription(int i) {

        String text = "";

        if (i == 1) {
            text = "<html><center><h2>#1 Bali Yoga Retreat</h2>"
                    + "Rejuvenate your mind and body with daily yoga sessions "
                    + "and organic meals in beautiful Bali.</center></html>";
        }
        else if (i == 2) {
            text = "<html><center><h2>#2 Sedona Spa Escape</h2>"
                    + "Relax with world-class spa treatments and scenic desert "
                    + "views in Sedona, Arizona.</center></html>";
        }
        else if (i == 3) {
            text = "<html><center><h2>#3 Costa Rica Wellness Resort</h2>"
                    + "Experience holistic wellness programs including detox "
                    + "diets, meditation, and nature hikes.</center></html>";
        }
        else if (i == 4) {
            text = "<html><center><h2>#4 Thailand Detox Sanctuary</h2>"
                    + "Cleanse your body at a detox sanctuary offering herbal "
                    + "therapies and Thai massages.</center></html>";
        }
        else if (i == 5) {
            text = "<html><center><h2>#5 Iceland Geothermal Spa</h2>"
                    + "Heal in natural hot springs surrounded by stunning "
                    + "Icelandic landscapes.</center></html>";
        }

        return text;
    }

    public static void main(String[] args) {

        EventQueue.invokeLater(() -> {
            SlideShow slideShow = new SlideShow();
            slideShow.setVisible(true);
        });
    }
}