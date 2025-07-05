package VISSOR.V4.src;

public abstract class Usuario_Operativo extends Usuario_Sistema {

    Usuario_Operativo (int idUsuario, String nombreUsuario, String sexo, String email, String passwordHash) {
        super(idUsuario, nombreUsuario, sexo, email, passwordHash);
    }
    abstract public void monitorearEstadoDeMaquinas();
    abstract public void recibirNotificacionesDeAlerta();
    abstract public void consultarHistorialBasicoDeDatosDeMaquina();
}
