package VISSOR.V4.UI;
import javax.swing.*;
import java.awt.*;

public class LoginUI extends JFrame {

    public LoginUI() {
        setTitle("Login - Sistema de Monitoreo");
        setSize(400, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // Centra la ventana
        setLayout(new BorderLayout());
        setResizable(false);

        // Panel de título
        JLabel lblTitulo = new JLabel("Iniciar Sesión", JLabel.CENTER);
        lblTitulo.setFont(new Font("Arial", Font.BOLD, 22));
        add(lblTitulo, BorderLayout.NORTH);

        // Panel central con formulario
        JPanel panelCentro = new JPanel(new GridLayout(4, 1, 10, 10));
        panelCentro.setBorder(BorderFactory.createEmptyBorder(20, 50, 20, 50));
        JTextField txtUsuario = new JTextField();
        JPasswordField txtPassword = new JPasswordField();
        JButton btnLogin = new JButton("Entrar");
        JTextField emaField = new JTextField();
       

        panelCentro.add(new JLabel("Nombre de usuario:"));
        panelCentro.add(txtUsuario);

        panelCentro.add(new JLabel("Correo electrónico:"));
        panelCentro.add(emaField);


        panelCentro.add(new JLabel("Contraseña:"));
        panelCentro.add(txtPassword);

        // Panel inferior con botón
        JPanel panelBoton = new JPanel();
        panelBoton.add(btnLogin);

        add(panelCentro, BorderLayout.CENTER);
        add(panelBoton, BorderLayout.SOUTH);

        // Acción para cambiar a dashboard 
        btnLogin.addActionListener(e -> {
            dispose(); // Cierra ventana actual
            new DashboardOperario(); // Abre dashboard
        });

        setVisible(true);
    }

    public static void main(String[] args) {
        new LoginUI();
    }
}
