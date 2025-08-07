package VISSOR.V4.src;
import VISSOR.V4.interfaces.I_Navegar;
public abstract class Usuario_Operativo extends Usuario_Sistema implements I_Navegar {

    Usuario_Operativo (int idUsuario, String nombreUsuario, String sexo, String email, String passwordHash) {
        super(idUsuario, nombreUsuario, sexo, email, passwordHash);
    }
    abstract public void monitorearEstadoDeMaquinas();
    abstract public void recibirNotificacionesDeAlerta();
    abstract public void consultarHistorialBasicoDeDatosDeMaquina();

    @Override
    public void irA(String destino) {
        System.out.println("Navegando a " + destino);
    }

    @Override
    public String obtenerUbicacionActual() {
        return "Ubicación actual del Usuario Operativo";
    }
}
