package VISSOR.V4.src;

public class Operativo extends Usuario_Operativo {

    public Operativo(int idUsuario, String nombreUsuario, String sexo, String email, String passwordHash) {
        super(idUsuario, nombreUsuario, sexo, email, passwordHash);
    }

    @Override
    public void monitorearEstadoDeMaquinas() {
        System.out.println("Monitoreando el estado de las máquinas...1");
    }
    @Override
    public void recibirNotificacionesDeAlerta() {
        System.out.println("Recibiendo notificaciones de alerta...1");
    }
    @Override
    public void consultarHistorialBasicoDeDatosDeMaquina() {    
        System.out.println("Consultando historial básico de datos de máquina...1");
    }
    @Override
    public void visualizarPanelPrincipal() {
        System.out.println("Visualizando panel principal del Usuario Operativo__");
    }

    public void filtrarHistorialPorUltimasHorasODias(String tipo, int cantidad) {
        if (tipo.equals("dias")) {
            System.out.println("Filtrando historial de " + cantidad + " días...");
        } else if (tipo.equals("horas")) {
            System.out.println("Filtrando historial de " + cantidad + " horas...");
        } else {
            System.out.println("Tipo de filtro no reconocido. Use 'dias' o 'horas'.");
        }
    }
}
