import static org.junit.Assert.*;
import org.junit.Test;


public class MyTests {

    @Test
    public  void Lampada_teste() {
        Lampada tester = new Lampada( "desligada" );
        assertEquals("init test", "desligada", tester.getEstado());
        tester.acende();
        assertEquals("acende test", "ligada", tester.getEstado());
        tester.apaga();
        assertEquals("apaga test", "desligada", tester.getEstado());
    }

    @Test
    public  void ContaBancaria_teste() {
        ContaBancaria tester = new ContaBancaria( "Mario", 500.0f, false );
        assertEquals(500.0f, tester.getSaldo(), 0);
        assertEquals(500f, tester.getSaldo(), 0);
        tester.deposita( 125.29f );
        assertEquals(625.29f, tester.getSaldo(), 0);
        tester.retira( 225.29f );
        assertEquals(400f, tester.getSaldo(), 0);
        tester.retira( 500f );
        assertEquals(400f, tester.getSaldo(), 0);
    }

    @Test
    public  void RegistroAcademico_teste() {
        RegistroAcademico tester = new RegistroAcademico( "Mario", 200134, false );
        assertEquals(1000f, tester.getMensalidade(1000f), 0);
        RegistroAcademico tester2 = new RegistroAcademico( "Outro Mario", 200134, true );
        assertEquals(500f, tester2.getMensalidade(1000f), 0);
    }
}
