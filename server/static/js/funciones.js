
var band_take = false;
var img_take
$(document).ready(function() {
    $("button").bind( "click" , function(){
        //console.log( $(this).attr("name") );


        if( $( this ).attr( 'name' ) != "m_push" ){
            



            $.ajax({
                type: 'POST',
                data: { id_p : $( this ).attr("name") } ,
                beforeSend: function(){ } ,
                success: function( data ){ 
                    console.log( data );

                }
            });




        }
    });




    
    $("button[name='m_push']").bind( "click" , function(){
        var some_html = '<img src="/static/photos/20140524213617.jpg" width="800px"/><br />';
        bootbox.alert( some_html );

            /*
            $.ajax({
                type: 'POST',
                data: { id_p : $( this ).attr("name") } ,
                beforeSend: function(){ } ,
                success: function( data ){ 
                    //$("#m_img").attr( "src" , "/static/photos/" + data )
                    console.log( data );
                    Modal.open({
                        content: '<img id="m_img" src="/static/photos/20140524213934.jpg" alt="">',
                        width: '70%', // Can be set to px, em, %, or whatever else is out there.
                        height: '70%',
                        hideclose: true, // Hides the close-modal graphic
                        closeAfter: 10 // Define this number in seconds.
                    });
                }
            });
            */
    });

});