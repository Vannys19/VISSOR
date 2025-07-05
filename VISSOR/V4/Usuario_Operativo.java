package VISSOR.V4;

public abstract class Usuario_Operativo extends Usuario_Sistema {

    Usuario_Operativo () {
        super();
    }


    void visualizarPanelPrincipal() {
        System.out.println("Ver panel principal de Usuario Operativo");
    }
    abstract public void monitorearEstadoDeMaquinas();
    abstract public void recibirNotificacionesDeAlerta();
    abstract public void consultarHistorialBasicoDeDatosDeMaquina();
}
