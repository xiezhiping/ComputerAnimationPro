import QtQuick 2.0
import QtQuick.Particles 2.0
Rectangle {
    id: root;
    width: 300; height: 160
    color: "#1f1f1f"
 
    ParticleSystem {
        id: particles
    }
 
    Emitter {
        id: emitter
        anchors.centerIn: parent
        width: 160; height: 80
        system: particles
        emitRate: 10
        lifeSpan: 1000
        lifeSpanVariation: 500
        size: 16
        endSize: 32
 
        Rectangle {
            anchors.fill: parent
            color: 'transparent'
            border.color: 'green'
            border.width: 2
            opacity: 0.8
        }
    }
 
    ItemParticle {
        system: particles
        delegate: Rectangle {
            id: rect
            width: 10
            height: 10
            color: "red"
            radius: 10
        }
    }
}
