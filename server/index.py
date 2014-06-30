import web , serial , re , os , time , datetime
"""
ser = serial.Serial(
    port = '/dev/ttyACM0' ,
    baudrate = 9600 ,
    timeout = 1
)
"""

urls = (
    '/(.*)', 'control'
)

t_globals = {
    'datestr': web.datestr
}

render = web.template.render( 'plantillas' , base = 'base' , globals=t_globals )

patron = re.compile('\d+')
MAX = 100
MIN = 0
BASE_DIR = os.path.dirname( os.path.dirname(__file__) )

"""
exo_btn 

s_izquierda
s_derecha 
s_medir 

temp_btn 

mp_arriba 
mp_abajo 

c_arriba 
c_izquierda 
c_izquierda2 
c_abajo 
c_derecha 
c_derecha2
 
"""



class control:
    def GET( self  , peticion ):
        return render.index()

    def POST( self , peticion ):
        data = web.input()
        id_p = data.get('id_p')
        if id_p == 'adelante':
            ser.write( chr( 0xfb ) )
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'atras':
            ser.write( chr( 0xfc ) )
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'izquierda':
            ser.write( chr( 0xfd ) )
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'derecha':
            ser.write( chr( 0xfe ) )
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'stop':
            ser.write( chr( 0xff ) )
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        # controles ipcam
        elif id_p == 'c_arriba':
            ser.write( chr( 0xf9 ) )
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'c_abajo':
            ser.write( chr( 0xfa ) )
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'c_derecha':
            ser.write( chr( 0xf8 ) )
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'c_izquierda':
            ser.write( chr( 0xf7 ) )
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'm_push':
            name_file = datetime.datetime.now().strftime('%Y%m%d%H%M%S') + ".jpg"
            #os.system( "sh photo.sh %s"%name_file )
            #time.sleep( 1.5 )
            return name_file

app = web.application( urls , globals() )
application = app.wsgifunc()
if __name__ == "__main__":
    app.run()
