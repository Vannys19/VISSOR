package VISSOR.V4.test;
import VISSOR.V4.src.Operativo;

public class Pruebas {
    public static void main(String[] args) {
        Operativo operativo = new Operativo(1, "Dave", "Masculino", "dave@vissor.com", "hashed_password");
        operativo.visualizarPanelPrincipal();
        operativo.monitorearEstadoDeMaquinas();
        operativo.recibirNotificacionesDeAlerta();
        operativo.consultarHistorialBasicoDeDatosDeMaquina();
        operativo.setNombreUsuario("DaveUpdated");
        System.out.println(operativo.getNombreUsuario());
        operativo.filtrarHistorialPorUltimasHorasODias("dias", 24);
    }
}