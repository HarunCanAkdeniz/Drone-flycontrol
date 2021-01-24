using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
public class yazi1 : MonoBehaviour
{
    private Vector3 sasa;
   
   
   string data;
    
   string[] datalar;
  
    SerialPort seri = new SerialPort("COM5", 9600);
    
    void Start()
    {
     
        seri.Open();
      
        
    }

    int xekseni, yekseni, zekseni;
    void Update()
    {

       // sasa = transform.rotation.eulerAngles;
        
        data = seri.ReadLine();
        datalar = data.Split('*');
        xekseni = int.Parse(datalar[0]);
        yekseni= int.Parse(datalar[1]);
        zekseni = int.Parse(datalar[2]);
        transform.rotation = Quaternion.Euler(xekseni,yekseni,zekseni);
        Camera.main.transform.position = transform.position+transform.forward*20+transform.up*8;

    }
}
