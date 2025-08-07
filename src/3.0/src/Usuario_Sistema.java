package VISSOR.V4.src;

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
    
    public int getIdUsuario() {
        return idUsuario;
    }

    public void setIdUsuario(int idUsuario) {
        this.idUsuario = idUsuario;
    }

    public String getNombreUsuario() {
        return nombreUsuario;
    }

    public void setNombreUsuario(String nombreUsuario) {
        this.nombreUsuario = nombreUsuario;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPasswordHash() {
        return passwordHash;
    }

    public void setPasswordHash(String passwordHash) {
        this.passwordHash = passwordHash;
    }

    abstract void visualizarPanelPrincipal();
}