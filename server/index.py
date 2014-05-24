import web , serial , re , os , time

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
        elif id_p == 'c_arriba':
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'c_abajo':
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'c_derecha':
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'c_izquierda':
            time.sleep( .1)
            return ser.read( ser.inWaiting() )
        elif id_p == 'm_push':
            return os.system( "sh photo.sh" )

app = web.application( urls , globals() )
application = app.wsgifunc()
if __name__ == "__main__":
    app.run()
