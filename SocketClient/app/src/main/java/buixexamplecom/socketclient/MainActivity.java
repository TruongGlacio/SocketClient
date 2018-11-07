package buixexamplecom.socketclient;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class MainActivity extends AppCompatActivity implements ClientSocket.ServerListener, ViewPager.OnPageChangeListener{

    TextView response_text;
    EditText editTextAddress, editTextPort,editsenData;
    Button buttonConnect, buttonClear,Button_Sendata;
    String text;
    String SMS=null;

    public BufferedWriter out;
    public BufferedReader in;
    public Socket socket;
    private Settings settings;
    private ClientSocket clientSocket;
    static final String TAG = "AndroidCheatSocket";
    private boolean connected = false;
    private MessengeListAdapter messengeListAdapter;
    private ClientSocket.ServerListener serverListener;
    String ip;
    int port;
    SharedPreferences mSharedPreferences;
     SharedPreferences.Editor mEditor;
  //  SharedPreferences.Editor mEditor=mSharedPreferences.edit();;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // khoi tao bien luu IP va port
         mSharedPreferences=this.getSharedPreferences("Mydata",MODE_APPEND);;
        mEditor=mSharedPreferences.edit();

        //............
        getIPandPort();
        editTextAddress = (EditText) findViewById(R.id.addressEditText);
        editTextPort = (EditText) findViewById(R.id.portEditText);
        editsenData=(EditText)findViewById(R.id.EditText_sendata);
        buttonConnect = (Button) findViewById(R.id.connectButton);
        Button_Sendata=(Button)findViewById(R.id.SendButton);
        buttonClear = (Button) findViewById(R.id.clearButton);
        response_text = (TextView) findViewById(R.id.responseTextView);

        buttonConnect.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View arg0) {
                if(!connected)

                {
                    try{
                    ip = editTextAddress.getText().toString();
                    port = Integer.valueOf(editTextPort.getText().toString());
                    String portString=port+"";
                    putIPandPort(ip,portString);
                }
                catch (Exception e){
                    Toast.makeText(getBaseContext(),"IP và Port không được để trống, Port phải là số nguyên \n Nhập lại",Toast.LENGTH_SHORT);
                }
                 try{
                   //  RequestData();
                     clientSocket = new ClientSocket(ip, port);
                     clientSocket.setServerListener(MainActivity.this);
                     buttonConnect.setText("Connecting to ESP");
                     response_text.setText("Android connected to ESP8266");
                     clientSocket.connect();

                     settings.putString(Settings.IP_ADDRESS, ip);
                     settings.putInt(Settings.PORT, port);

                    // connect(ip,port);*/

                 }
                 catch (Exception e)
                 {
                     buttonConnect.setText("Port Disconnected");
                 }
                }else{
                    try{clientSocket.disconnect();
                        }
                    catch (Exception e)
                    {
                        buttonConnect.setText("Disconnect");
                    }

                }

            }
        });

        Button_Sendata.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                String Data="ASE1234";
                try{
                    Data=""+editsenData.getText().toString();}
                catch (Exception e){
                    Toast.makeText(getBaseContext(),"Bạn Chưa nhập gì, nhập lại",Toast.LENGTH_SHORT);
                }

              try {
                  clientSocket.sendMessenge(Data, messengeListAdapter);
              }
              catch (Exception e){
                  Toast.makeText(getBaseContext(),"Gửi Lỗi" + e.toString(),Toast.LENGTH_SHORT);
              }

            }
        });
        buttonClear.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                response_text.setText("Type Data");
            }
        });
    }
    public void putIPandPort(String IP, String Port)
    {
       // mSharedPreferences=this.getSharedPreferences("MyData",MODE_APPEND);
      //  SharedPreferences.Editor mEditor=mSharedPreferences.edit();
      //  Boolean rememberdata=mSharedPreferences.getBoolean("Remember",true);
        try {

            mEditor.putString("IP",IP+"");
            mEditor.putString("Port",Port+"");
            mEditor.putBoolean("Remember", false);

            mEditor.commit();

            editTextAddress.setText(IP+"");
            editTextPort.setText(Port+"");
          //  Toast.makeText(getBaseContext(),"Da luu muc canh bao va muc bao dong",Toast.LENGTH_SHORT).show();
        }
        catch (Exception e){
            Toast.makeText(getBaseContext(),"Có lỗi putstring xảy ra"+e.toString(),Toast.LENGTH_SHORT).show();
        }
    }
    public void getIPandPort()
    {

        try{// lấy ngưỡng cảnh báo và báo động từ SharePreference
            Boolean rememberdata=mSharedPreferences.getBoolean("Remember",false);
           // SharedPreferences.Editor mEditor=mSharedPreferences.edit();
            String IP=mSharedPreferences.getString("IP","192.168.1.80");//doc gia tri b1 tu SharePreferences, neu do loi thi lay mac dinh b2 la 40.0
            String Port=mSharedPreferences.getString("Port","80");//doc gia tri a1 tu SharePreferences, neu do loi thi lay mac dinh b2 la 35.0
            editTextAddress.setText(IP+"");
            editTextPort.setText(Port+"");
        }
        catch (Exception e){
            Toast.makeText(getBaseContext(),"Đã xảy  ra lỗi getstring"+e.toString(),Toast.LENGTH_SHORT).show();
        }
    }
    public void connect(String IP,int Port) {
        try {
            Socket socket = new Socket(IP, Port);
            // Sending to server
            PrintStream ps = new PrintStream(socket.getOutputStream());
            buttonConnect.setText("Connecting to ESP");

            // Receiving from server
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String response = br.readLine();
            if (response!=null){
                response_text.setText("Server answered: " + response);
                System.out.println("Server answered: " + response);
            }
        } catch (UnknownHostException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }}
    public void  RequestData(){
        RequestQueue queue = Volley.newRequestQueue(this);

        String url =editTextAddress.getText().toString();//"http://www.google.com";

// Request a string response from the provided URL.
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        response_text.setText("Response: " + response.toString());
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
              response_text.setText("That didn't work!");
            }
        });
// Add the request to the RequestQueue.
        queue.add(stringRequest);

// Access the RequestQueue through your singleton class.
       // MySingleton.getInstance(this).addToRequestQueue(jsObjRequest);
    }
    @Override
    public void connectStatusChange(boolean status) {
        this.connected = status;
        this.buttonConnect.setText(status ? "DISCONNECT" : "CONNECT TO ESP");
        this.editTextAddress.setEnabled(!status);
        this.editTextPort.setEnabled(!status);
    }

    @Override
    public void newMessengeFromServer(String messenge) {
        messengeListAdapter.addMessenge(new MessengeItem(MessengeItem.TYPE_IN, messenge));
    }

    @Override
    public String ReadData(String messenge) {
        try {
            messenge = in.readLine();
            while (messenge != null){
                messenge = in.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            socket.close();
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return messenge;
    }

    @Override
    public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) {

    }

    @Override
    public void onPageSelected(int position) {

    }

    @Override
    public void onPageScrollStateChanged(int state) {

    }
}
