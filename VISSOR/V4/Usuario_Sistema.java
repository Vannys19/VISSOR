package VISSOR.V4;

public abstract class Usuario_Sistema {
    private int idUsuario;
    private String nombreUsuario;
    private String sexo;
    private String email;
    private String passwordHash;

    public Usuario_Sistema(int idUsuario, String nombreUsuario, String sexo, String email, String passwordHash) {
        this.idUsuario = idUsuario;
        this.nombreUsuario = nombreUsuario;
        this.sexo = sexo;
        this.email = email;
        this.passwordHash = passwordHash;
    }

    abstract void visualizarPanelPrincipal();
}
