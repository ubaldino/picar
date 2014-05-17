import web
import serial
import re
import os

"""
ser = serial.Serial(
    port = '/dev/ttyACM0' ,
    baudrate = 9600 ,
    timeout = 1
)
"""

urls = (
    '/', 'control'
)
app = web.application(urls, globals())

t_globals = {
    'datestr': web.datestr
}
render = web.template.render( 'plantillas' , base = 'base' , globals=t_globals )

patron = re.compile('\d+')
MAX = 100
MIN = 0
BASE_DIR = os.path.dirname( os.path.dirname(__file__) )

class control:
    def GET( self  ):
        return render.index()

    def POST( self ):
        data = web.input()
        id_p = data.get('id_p')
        if id_p == 'adelante':
            os.system( "python /root/fw.py" )
        elif id_p == 'atras':
            os.system( "python /root/back.py" )
        return id_p

application = app.wsgifunc()
##  deshabilit for ng
if __name__ == "__main__":
    app.run()