package VISSOR.V4.UI;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import javax.swing.border.TitledBorder;

public class DashboardOperario extends JFrame {

    // Define colors from the Adobe Color theme using RGB
    private static final Color PRIMARY_DARK_BLUE = new Color(41, 117, 217);      // rgb(41, 117, 217) - Strongest Blue, for headers/main accents
    private static final Color PRIMARY_MEDIUM_BLUE = new Color(89, 159, 242);    // rgb(89, 159, 242) - Lighter Blue, for buttons/interactive elements
    private static final Color ACCENT_LIGHT_BLUE = new Color(139, 202, 217);     // rgb(139, 202, 217) - Very Light Blue/Teal, for cards/highlights on dark background
    
    // Adjusted grayscale names for clarity, as your original "light gray" was quite dark
    private static final Color BACKGROUND_MAIN_DARK = new Color(51, 51, 51);     // rgb(51, 51, 51) - Main dark background
    private static final Color BACKGROUND_SIDEBAR_DARKER = new Color(43, 43, 43); // rgb(43, 43, 43) - Darker gray for sidebar
    private static final Color TEXT_ON_DARK_BACKGROUND = Color.WHITE;             // rgb(255, 255, 255) - White text for dark backgrounds
    private static final Color TEXT_ON_LIGHT_BACKGROUND = new Color(30, 30, 30);  // rgb(30, 30, 30) - Dark text for light backgrounds

    public DashboardOperario() {
        setTitle("Panel Principal - Operador");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        setSize(1000, 700); 
        
        // Panel que contendrá el título y el separador en el header
        JPanel combinedHeaderPanel = new JPanel(new BorderLayout());
        combinedHeaderPanel.setBackground(BACKGROUND_SIDEBAR_DARKER); // Background for the whole header area

        // Panel para el título del header (va en el CENTER de combinedHeaderPanel)
        JPanel headerTitlePanel = new JPanel(new BorderLayout());
        headerTitlePanel.setOpaque(false); // Make it transparent
        headerTitlePanel.setPreferredSize(new Dimension(getWidth(), 70)); // Control height
        
        JLabel lblTitulo = new JLabel("Panel Principal - Usuario Operativo");
        lblTitulo.setFont(new Font("Arial", Font.BOLD, 22)); 
        lblTitulo.setForeground(TEXT_ON_DARK_BACKGROUND); 
        lblTitulo.setBorder(BorderFactory.createEmptyBorder(15, 30, 15, 10)); 
        headerTitlePanel.add(lblTitulo, BorderLayout.WEST);
        
        // Crea el JSeparator (la barrita/línea) para el header
        JSeparator headerSeparator = new JSeparator(SwingConstants.HORIZONTAL);
        headerSeparator.setForeground(Color.WHITE); 
        headerSeparator.setPreferredSize(new Dimension(1, 1)); // Altura de 2 píxeles

        // Añade el panel del título y el separador al panel combinado del header
        combinedHeaderPanel.add(headerTitlePanel, BorderLayout.CENTER);
        combinedHeaderPanel.add(headerSeparator, BorderLayout.SOUTH);
        
        // Panel izquierdo (sidebar) - Vuelve a usar GridLayout
        JPanel sidebar = new JPanel(); 
        sidebar.setBackground(BACKGROUND_SIDEBAR_DARKER); 
        sidebar.setPreferredSize(new Dimension(250, getHeight())); 
        sidebar.setLayout(new GridLayout(10, 1, 0, 0)); // Vuelve a tu GridLayout original

        JPanel userPanel = new JPanel(new BorderLayout());
        userPanel.setBackground(PRIMARY_DARK_BLUE);
        userPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10)); // Espacio alrededor del panel del usuario
        JLabel userLabel = new JLabel("Juan Pérez");
        userLabel.setForeground(TEXT_ON_DARK_BACKGROUND);
        userLabel.setFont(new Font("Arial", Font.BOLD, 16));
        userPanel.add(userLabel, BorderLayout.CENTER);
        userPanel.setPreferredSize(new Dimension(200, 60)); // Ajusta el tamaño del panel del usuario
        sidebar.add(userPanel); // Añade el panel del usuario al sidebar

        String[] opciones = {"+ Agregar nuevo", "Alertas", "Cerrar sesión"};
        for (String texto : opciones) {
            JButton btn = new JButton(texto);
            btn.setFocusPainted(false);
            btn.setBackground(null); // Elimina el fondo para que se vea el del sidebar
            btn.setForeground(TEXT_ON_DARK_BACKGROUND); 
            btn.setFont(new Font("Arial", Font.BOLD, 14)); 
            btn.setBorder(null); // Elimina el borde para un look más limpio
            btn.setOpaque(true); // Asegura que el botón tenga un fondo visible
            sidebar.add(btn); // Añade los botones directamente al sidebar con GridLayout
        }


        // Panel central principal
        JPanel mainPanel = new JPanel(new BorderLayout());
        mainPanel.setBackground(BACKGROUND_MAIN_DARK); 

        // Tarjetas informativas
        JPanel tarjetas = new JPanel(new GridLayout(1, 4, 20, 20)); 
        tarjetas.setBorder(BorderFactory.createEmptyBorder(30, 30, 20, 30)); 
        tarjetas.setBackground(BACKGROUND_MAIN_DARK); 
        tarjetas.add(crearTarjeta("Máquinas activas", "8"));
        tarjetas.add(crearTarjeta("Alertas recibidas", "3"));
        tarjetas.add(crearTarjeta("Historial filtrado", "Últimas 24h"));
        tarjetas.add(crearTarjeta("Estado general", "Estable"));

        // Panel combinado: filtros + tabla
        JPanel centro = new JPanel(new BorderLayout(15, 15)); 
        centro.setBorder(BorderFactory.createEmptyBorder(0, 30, 30, 30)); 
        centro.setBackground(BACKGROUND_MAIN_DARK); 

        // Panel de filtros estilo "Filter Rules"
        JPanel panelFiltros = new JPanel(new GridLayout(3, 3, 10, 10));
        TitledBorder titleBorder = BorderFactory.createTitledBorder("Filtros Condicionales");
        titleBorder.setTitleColor(TEXT_ON_DARK_BACKGROUND);
        panelFiltros.setBorder(titleBorder);
        panelFiltros.setBackground(BACKGROUND_MAIN_DARK); 

        // Set background and foreground for combo boxes and text fields for consistency
        JComboBox<String> categoria1 = new JComboBox<>(new String[]{"Dispositivo", "Estado", "Fecha"});
        categoria1.setBackground(TEXT_ON_DARK_BACKGROUND); 
        categoria1.setForeground(TEXT_ON_LIGHT_BACKGROUND); 
        JComboBox<String> operador1 = new JComboBox<>(new String[]{"contiene", "igual a", "comienza con"});
        operador1.setBackground(TEXT_ON_DARK_BACKGROUND);
        operador1.setForeground(TEXT_ON_LIGHT_BACKGROUND);
        JTextField valor1 = new JTextField();
        valor1.setBackground(TEXT_ON_DARK_BACKGROUND);
        valor1.setForeground(TEXT_ON_LIGHT_BACKGROUND);
        valor1.setCaretColor(TEXT_ON_LIGHT_BACKGROUND); 

        JComboBox<String> categoria2 = new JComboBox<>(new String[]{"Dispositivo", "Estado", "Fecha"});
        categoria2.setBackground(TEXT_ON_DARK_BACKGROUND);
        categoria2.setForeground(TEXT_ON_LIGHT_BACKGROUND);
        JComboBox<String> operador2 = new JComboBox<>(new String[]{"contiene", "igual a", "comienza con"});
        operador2.setBackground(TEXT_ON_DARK_BACKGROUND);
        operador2.setForeground(TEXT_ON_LIGHT_BACKGROUND);
        JTextField valor2 = new JTextField();
        valor2.setBackground(TEXT_ON_DARK_BACKGROUND);
        valor2.setForeground(TEXT_ON_LIGHT_BACKGROUND);
        valor2.setCaretColor(TEXT_ON_LIGHT_BACKGROUND);

        JButton aplicar = new JButton("Aplicar");
        aplicar.setBackground(PRIMARY_MEDIUM_BLUE); 
        aplicar.setForeground(TEXT_ON_DARK_BACKGROUND); 
        aplicar.setFont(new Font("Arial", Font.BOLD, 14));

        panelFiltros.add(categoria1);
        panelFiltros.add(operador1);
        panelFiltros.add(valor1);

        panelFiltros.add(categoria2);
        panelFiltros.add(operador2);
        panelFiltros.add(valor2);

        panelFiltros.add(new JLabel()); 
        panelFiltros.add(aplicar);

        String[] columnas = {"ID", "Dispositivo", "Estado", "Fecha", "Hora"};
        Object[][] datos = {
            {"001", "Sensor A", "Activo", "04/07/2025", "10:00"},
            {"002", "Sensor B", "Error", "04/07/2025", "10:05"},
            {"003", "Motor X", "Revisar", "04/07/2025", "10:10"},
            {"004", "Motor Y", "Activo", "04/07/2025", "10:15"},
            {"005", "Sensor C", "Alerta", "04/07/2025", "10:20"},
            {"006", "Sensor A", "Activo", "04/07/2025", "10:25"},
            {"007", "Motor X", "Revisar", "04/07/2025", "10:30"}
        };

        JTable tabla = new JTable(new DefaultTableModel(datos, columnas));
        tabla.setBackground(BACKGROUND_MAIN_DARK); 
        tabla.setForeground(TEXT_ON_LIGHT_BACKGROUND); 
        tabla.setRowHeight(25); 
        tabla.setFont(new Font("Arial", Font.PLAIN, 12));

        tabla.getTableHeader().setBackground(PRIMARY_DARK_BLUE); 
        tabla.getTableHeader().setForeground(TEXT_ON_DARK_BACKGROUND); 
        tabla.getTableHeader().setFont(new Font("Arial", Font.BOLD, 13)); 
        tabla.getTableHeader().setReorderingAllowed(false); 
        tabla.getTableHeader().setResizingAllowed(false); 

        JScrollPane scrollTabla = new JScrollPane(tabla);
        scrollTabla.getViewport().setBackground(BACKGROUND_MAIN_DARK); 
        scrollTabla.setBorder(BorderFactory.createLineBorder(PRIMARY_MEDIUM_BLUE, 2)); 

        centro.add(panelFiltros, BorderLayout.NORTH);
        centro.add(scrollTabla, BorderLayout.CENTER);

        mainPanel.add(tarjetas, BorderLayout.NORTH);
        mainPanel.add(centro, BorderLayout.CENTER);

        // Añadir todo a la ventana
        add(sidebar, BorderLayout.WEST);
        add(combinedHeaderPanel, BorderLayout.NORTH); // Añade el nuevo panel combinado del header
        add(mainPanel, BorderLayout.CENTER);

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private JPanel crearTarjeta(String titulo, String valor) {
        JPanel tarjeta = new JPanel();
        tarjeta.setLayout(new BorderLayout(10, 5)); 
        tarjeta.setBackground(ACCENT_LIGHT_BLUE); 
        tarjeta.setBorder(BorderFactory.createLineBorder(PRIMARY_MEDIUM_BLUE, 2)); 
        tarjeta.setPreferredSize(new Dimension(150, 90)); 

        JLabel lblTitulo = new JLabel(titulo, JLabel.CENTER);
        lblTitulo.setFont(new Font("Arial", Font.PLAIN, 15)); 
        lblTitulo.setForeground(TEXT_ON_LIGHT_BACKGROUND); 
        lblTitulo.setBorder(BorderFactory.createEmptyBorder(10, 0, 0, 0)); 

        JLabel lblValor = new JLabel(valor, JLabel.CENTER);
        lblValor.setFont(new Font("Arial", Font.BOLD, 30)); 
        lblValor.setForeground(PRIMARY_DARK_BLUE); 
        lblValor.setBorder(BorderFactory.createEmptyBorder(0, 0, 10, 0)); 

        tarjeta.add(lblTitulo, BorderLayout.NORTH);
        tarjeta.add(lblValor, BorderLayout.CENTER);
        return tarjeta;
    }
    public static void main(String[] args) {
        SwingUtilities.invokeLater(DashboardOperario::new);
    }
}